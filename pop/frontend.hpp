#ifndef POP_FRONTEND_HPP
#define POP_FRONTEND_HPP

#define POP_INSIDE_FRONTEND_HEADER_

#include <pop/frontend/ast.hpp>
#include <pop/frontend/compiler.hpp>
#include <pop/frontend/constant.hpp>
#include <pop/frontend/constants-table.hpp>
#include <pop/frontend/define-symbols.hpp>
#include <pop/frontend/dot.hpp>
#include <pop/frontend/instruction-compiler.hpp>
#include <pop/frontend/instruction-dumper.hpp>
#include <pop/frontend/instruction-list.hpp>
#include <pop/frontend/instruction-optimizer.hpp>
#include <pop/frontend/instruction-resolver.hpp>
#include <pop/frontend/instructions.hpp>
#include <pop/frontend/instruction-visitor.hpp>
#include <pop/frontend/link-parents.hpp>
#include <pop/frontend/location-patcher.hpp>
#include <pop/frontend/operators.hpp>
#include <pop/frontend/resolve-symbols.hpp>
#include <pop/frontend/symbol-table.hpp>
#include <pop/frontend/type-code.hpp>
#include <pop/frontend/type-info.hpp>
#include <pop/frontend/validate.hpp>
#include <pop/frontend/visitor.hpp>

#undef POP_INSIDE_FRONTEND_HEADER_

#endif // POP_FRONTEND_HPP
