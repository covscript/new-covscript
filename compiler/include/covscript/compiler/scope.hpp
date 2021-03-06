//
// Created by kiva on 2019/9/19.
//
#pragma once

#include <covscript/compiler/variable.hpp>
#include <covscript/compiler/callState.hpp>
#include <unordered_map>
#include <utility>

namespace cs {
    namespace compiler {
        class Scope {
        private:
            Scope *_parent;
            std::unordered_map<VMString, Variable *> _variables;

        public:
            explicit Scope(Scope *parent);

            ~Scope() = default;

            Variable *search(const VMString &name);

            Scope *getParent() { return _parent; };

            void set(const Parameter &param, const Argument &arg);

            void set(const std::pair<Parameter, Argument> &pair);
        };
    }
}
