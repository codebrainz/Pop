#include <Pop/Compiler.hpp>
#include <Pop/DefineSymbols.hpp>
#include <Pop/DOT.hpp>
#include <Pop/Grammar.hpp>
#include <Pop/Instructions.hpp>
#include <Pop/Lexer.hpp>
#include <Pop/LinkParents.hpp>
#include <Pop/LocationPatcher.hpp>
#include <Pop/ParseState.hpp>
#include <Pop/ResolveSymbols.hpp>
#include <Pop/Validate.hpp>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

namespace Pop {

  Compiler::Compiler() : program(new Program(new NodeList())) {
  }

  Compiler::~Compiler() {
    for (auto fn : filenames)
      std::free(fn);
    node_unref(program);
  }

  Node *Compiler::parse_file(const std::string &fn) {
    std::ifstream f(fn);
    return parse_file(fn, f);
  }

  Node *Compiler::parse_file(const std::string &fn, std::istream &is) {
    auto filename = add_fn(fn);
    ParseState state(filename, is, *this);
    yyparse(&state);
    auto mod = new Module(filename, 0, 0, state.roots);
    state.roots = nullptr;
    dynamic_cast< NodeList * >(program->modules)->append_take(mod);
    return mod;
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

  void Compiler::compile_instructions() {
  }

  void Compiler::dump_instructions(std::ostream &out) {
    Pop::dump_instructions(instructions, out);
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
    auto f = strdup(fn.c_str());
    filenames.push_back(f);
    return f;
  }

  // namespace Pop
}
