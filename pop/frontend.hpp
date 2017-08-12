#ifndef POP_FRONTEND_HPP
#define POP_FRONTEND_HPP

#include <pop/common.hpp>
#include <pop/ir.hpp>

#define POP_INSIDE_FRONTEND_HEADER_

#include <pop/frontend/define-symbols.hpp>
#include <pop/frontend/dot.hpp>
#include <pop/frontend/instruction-compiler.hpp>
#include <pop/frontend/link-parents.hpp>
#include <pop/frontend/location-patcher.hpp>
#include <pop/frontend/parser.hpp>
#include <pop/frontend/resolve-symbols.hpp>
#include <pop/frontend/symbol-table.hpp>
#include <pop/frontend/validate.hpp>

#undef POP_INSIDE_FRONTEND_HEADER_

#endif // POP_FRONTEND_HPP
