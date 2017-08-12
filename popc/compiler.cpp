#ifdef HAVE_CONFIG_H
#include <pop/config.h>
#endif

#include <popc/compiler.hpp>

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

namespace Pop {

  Compiler::Compiler() : program(new Program(new NodeList())) {
  }

  Compiler::~Compiler() {
    for (auto fn : filenames)
      std::free(fn);
    node_unref(program);
  }

  Node *Compiler::parse_file(const std::string &fn) {
    if (fn.empty())
      return nullptr;
    return Pop::parse_file(program, log, add_fn(fn));
  }

  Node *Compiler::parse_file(const std::string &fn, std::istream &is) {
    return Pop::parse_file(program, log, is, add_fn(fn));
  }

  void Compiler::link_parents(bool verify) {
    Pop::link_parents(program, log, verify);
  }

  void Compiler::define_symbols() {
    Pop::define_symbols(program, log);
  }

  void Compiler::resolve_symbols() {
    Pop::resolve_symbols(program, log);
  }

  void Compiler::patch_locations(bool verify) {
    Pop::patch_locations(program, log, verify);
  }

  void Compiler::validate() {
    Pop::validate(program, log);
  }

  void Compiler::generate_dot(std::ostream &os,
                              const std::string &indent_token) {
    Pop::generate_dot(program, os, indent_token);
  }

  void Compiler::compile_instructions(bool line_directives) {
    Pop::compile_instructions(program, const_tab, instructions,
                              line_directives);
  }

  void Compiler::resolve_instructions(bool prune_labels) {
    Pop::resolve_instructions(instructions, prune_labels);
  }

  void Compiler::optimize_instructions() {
    Pop::optimize_instructions(instructions);
  }

  void Compiler::dump_instructions(std::ostream &out) {
    Pop::dump_instructions(instructions, const_tab, out);
  }

  int Compiler::report_diagnostics(int max_errors) {
    return report_diagnostics(std::cerr, max_errors);
  }

  int Compiler::report_diagnostics(std::ostream &os, int max_errors) {
    return log.report_messages(os, max_errors);
  }

  const char *Compiler::add_fn(const std::string &fn) {
    for (auto f : filenames) {
      if (std::strcmp(f, fn.c_str()) == 0)
        return f;
    }
    auto f = Pop::strdup(fn.c_str());
    filenames.push_back(f);
    return f;
  }

  // namespace Pop
}
