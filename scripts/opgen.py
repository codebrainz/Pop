#!/usr/bin/env python3

import jinja2
import optparse
import os
import subprocess
import sys
import xml.etree.ElementTree as ET

class Instruction:
  def __init__(self, name, mnemonic, fields=[], size=1):
    self.name = name
    self.mnemonic = mnemonic
    self.fields = fields
    self.size = size
  @property
  def node_fields(self):
    return [ f for f in self.fields if f.type == "Node*" ]
  @property
  def construct_fields(self):
    return [ f for f in self.fields if f.construct ]

class InstructionField:
    def __init__(self, name, type, construct=True, default=None):
      self.name = name
      self.type = type
      self.construct = construct
      self.default = default

def parse_instructions(root):
  instructions = []
  for node_elem in root.iterfind('instructions/node'):
    name = node_elem.attrib['name']
    mnemonic = node_elem.attrib.get('mnemonic', None)
    size = int(node_elem.attrib.get('size', '1'))
    fields = []
    for field_elem in node_elem.iterfind('field'):
      fields.append(InstructionField(
        field_elem.attrib['name'],
        field_elem.attrib['type'],
        True if field_elem.attrib.get('construct', "true") in [ "yes", "true" ] else False,
        field_elem.attrib.get('default', None)
      ))
    instructions.append(Instruction(name, mnemonic, fields, size))
  return instructions

def do_format(fn):
  def can_format():
    if fn == '-':
      return False
    try:
      with open(os.devnull) as nulfile:
        subprocess.call([ "clang-format", "--version"], stdout=nulfile, stderr=nulfile)
      return os.path.exists(os.path.join(os.path.dirname(__file__), "..", ".clang-format"))
    except FileNotFoundError as e:
      return False
  if can_format():
    subprocess.call([ "clang-format", "-i", "-style=file", fn ])

def main(args):
  par = optparse.OptionParser(
    usage='Usage: %prog [options] DIR'
  )

  par.add_option('-d', '--data', metavar='FILE', dest='data_fn',
    help='the xml data file')
  par.add_option('-t', '--template', metavar='FILE', dest='tmpl_fn',
    help='the C template file to use for generated files')

  opts, args = par.parse_args(args[1:])

  data_fn = opts.data_fn
  if not os.path.exists(data_fn):
    par.error("unable to find data file '%'" % data_fn)
  xml_root = ET.ElementTree(file=data_fn)

  if len(args) < 1:
    par.error('missing input directory argument')
  elif len(args) > 1:
    par.error('too many input directories specified, expecting one')
  input_dir = args[0]
  if not os.path.exists(input_dir):
    par.error("unable to find input directory '%'" % input_dir)

  tmpl_fn = opts.tmpl_fn
  if not tmpl_fn:
    tmpl_fn = os.path.join(input_dir, 'template.c.in')
  if not os.path.exists(tmpl_fn):
    par.error("unable to find template file '%s'" % tmpl_fn)

  instructions = parse_instructions(xml_root)

  entries = {}
  for f in os.listdir(input_dir):
    pth = os.path.join(input_dir, f)
    if os.path.isfile(pth) and f.startswith('op_') and f.endswith('.c'):
      entries[f] = pth

  with open(tmpl_fn, 'r') as tmpl_file:
    tmpl_text = tmpl_file.read()
    for code, instruction in enumerate(instructions):
      bn = 'op_%s.c' % instruction.mnemonic.lower()
      fn = os.path.join(input_dir, bn)
      if bn not in entries and not os.path.exists(fn):
        with open(fn, 'w') as f:
          t = jinja2.Template(tmpl_text)
          s = t.render(
            mnemonic = instruction.mnemonic,
            codehex = '%02X' % code
          )
          f.write(s.rstrip() + '\n')
        do_format(fn)

  make_file = os.path.join(input_dir, 'op_sources.mk')
  with open(make_file, 'w') as f:
    f.write('popvm_op_sources = \\\n')
    for i,instruction in enumerate(instructions):
      f.write('\t$(top_srcdir)/popvm/ops/op_%s.c' % instruction.mnemonic.lower())
      if i < (len(instructions) - 1):
        f.write(' \\')
      f.write('\n')

  return 0

if __name__ == "__main__":
  sys.exit(main(sys.argv))
