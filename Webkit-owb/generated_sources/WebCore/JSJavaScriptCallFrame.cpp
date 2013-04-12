/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

/*
* This file was modified by Electronic Arts Inc Copyright � 2009-2010
*/

#include "config.h"

#include "JSJavaScriptCallFrame.h"

#include <wtf/GetPtr.h>

#include "JSJavaScriptCallFrame.h"
#include "JavaScriptCallFrame.h"
#include "KURL.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashTableValue JSJavaScriptCallFrameTableValues[8] =
{
    { "caller", (intptr_t)JSJavaScriptCallFrame::CallerAttrNum, DontDelete|ReadOnly, 0 },
    { "sourceIdentifier", (intptr_t)JSJavaScriptCallFrame::SourceIdentifierAttrNum, DontDelete|ReadOnly, 0 },
    { "line", (intptr_t)JSJavaScriptCallFrame::LineAttrNum, DontDelete|ReadOnly, 0 },
    { "scopeChain", (intptr_t)JSJavaScriptCallFrame::ScopeChainAttrNum, DontDelete|ReadOnly, 0 },
    { "thisObject", (intptr_t)JSJavaScriptCallFrame::ThisObjectAttrNum, DontDelete|ReadOnly, 0 },
    { "functionName", (intptr_t)JSJavaScriptCallFrame::FunctionNameAttrNum, DontDelete|ReadOnly, 0 },
    { "type", (intptr_t)JSJavaScriptCallFrame::TypeAttrNum, DontDelete|ReadOnly, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSJavaScriptCallFrameTable = { 63, JSJavaScriptCallFrameTableValues, 0 };

/* Hash table for prototype */

static const HashTableValue JSJavaScriptCallFramePrototypeTableValues[2] =
{
    { "evaluate", (intptr_t)jsJavaScriptCallFramePrototypeFunctionEvaluate, DontDelete|Function, 1 },
    { 0, 0, 0, 0 }
};

static const HashTable JSJavaScriptCallFramePrototypeTable = { 0, JSJavaScriptCallFramePrototypeTableValues, 0 };

const ClassInfo JSJavaScriptCallFramePrototype::s_info = { "JavaScriptCallFramePrototype", 0, &JSJavaScriptCallFramePrototypeTable, 0 };

JSObject* JSJavaScriptCallFramePrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSJavaScriptCallFrame.prototype]]");
    return KJS::cacheGlobalObject<JSJavaScriptCallFramePrototype>(exec, prototypeIdentifier);
}

bool JSJavaScriptCallFramePrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSJavaScriptCallFramePrototypeTable, this, propertyName, slot);
}

const ClassInfo JSJavaScriptCallFrame::s_info = { "JavaScriptCallFrame", 0, &JSJavaScriptCallFrameTable , 0 };

JSJavaScriptCallFrame::JSJavaScriptCallFrame(JSObject* prototype, JavaScriptCallFrame* impl)
    : DOMObject(prototype)
    , m_impl(impl)
{
}

JSJavaScriptCallFrame::~JSJavaScriptCallFrame()
{
    ScriptInterpreter::forgetDOMObject(m_impl.get());

}

bool JSJavaScriptCallFrame::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSJavaScriptCallFrame, Base>(exec, &JSJavaScriptCallFrameTable, this, propertyName, slot);
}

JSValue* JSJavaScriptCallFrame::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case CallerAttrNum: {
        JavaScriptCallFrame* imp = static_cast<JavaScriptCallFrame*>(impl());
        return toJS(exec, WTF::getPtr(imp->caller()));
    }
    case SourceIdentifierAttrNum: {
        JavaScriptCallFrame* imp = static_cast<JavaScriptCallFrame*>(impl());
        return jsNumber(exec, imp->sourceIdentifier());
    }
    case LineAttrNum: {
        JavaScriptCallFrame* imp = static_cast<JavaScriptCallFrame*>(impl());
        return jsNumber(exec, imp->line());
    }
    case ScopeChainAttrNum: {
        return scopeChain(exec);
    }
    case ThisObjectAttrNum: {
        return thisObject(exec);
    }
    case FunctionNameAttrNum: {
        JavaScriptCallFrame* imp = static_cast<JavaScriptCallFrame*>(impl());
        return jsString(exec, imp->functionName());
    }
    case TypeAttrNum: {
        return type(exec);
    }
    }
    return 0;
}

JSValue* jsJavaScriptCallFramePrototypeFunctionEvaluate(ExecState* exec, JSObject*, JSValue* thisValue, const ArgList& args)
{
    if (!thisValue->isObject(&JSJavaScriptCallFrame::s_info))
        return throwError(exec, TypeError);
    JSJavaScriptCallFrame* castedThisObj = static_cast<JSJavaScriptCallFrame*>(thisValue);
    return castedThisObj->evaluate(exec, args);
}

KJS::JSValue* toJS(KJS::ExecState* exec, JavaScriptCallFrame* obj)
{
    return cacheDOMObject<JavaScriptCallFrame, JSJavaScriptCallFrame, JSJavaScriptCallFramePrototype>(exec, obj);
}
JavaScriptCallFrame* toJavaScriptCallFrame(KJS::JSValue* val)
{
    return val->isObject(&JSJavaScriptCallFrame::s_info) ? static_cast<JSJavaScriptCallFrame*>(val)->impl() : 0;
}

}
