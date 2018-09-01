/*******************************************************************************
* Copyright 2017-2018 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "ngraph/op/custom.hpp"

using namespace std;
using namespace ngraph;

op::Custom::Custom(const string& name, const NodeVector& args)
    : Op(name, args)
{
}

void op::Custom::register_exec(const std::string& backend, execute_t f)
{
    m_execute_collection.insert({backend, f});
}

op::Custom::execute_t op::Custom::get_exec(const std::string& backend_name) const
{
    auto it = m_execute_collection.find(backend_name);
    if (it == m_execute_collection.end())
    {
        throw runtime_error("Custom op '" + get_friendly_name() +
                            "' does not have an execute function for backend '" + backend_name +
                            "'");
    }
    return it->second;
}

void op::Custom::generate_adjoints(autodiff::Adjoints& adjoints, const NodeVector& deltas)
{
}
