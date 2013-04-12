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

#ifndef JSCounter_h
#define JSCounter_h

#include "JSDOMBinding.h"
#include <kjs/JSGlobalObject.h>
#include <kjs/ObjectPrototype.h>

namespace WebCore {

class Counter;

class JSCounter : public DOMObject {
    typedef DOMObject Base;
public:
    JSCounter(KJS::JSObject* prototype, Counter*);
    virtual ~JSCounter();
    virtual bool getOwnPropertySlot(KJS::ExecState*, const KJS::Identifier& propertyName, KJS::PropertySlot&);
    KJS::JSValue* getValueProperty(KJS::ExecState*, int token) const;
    virtual const KJS::ClassInfo* classInfo() const { return &s_info; }
    static const KJS::ClassInfo s_info;

    static KJS::JSValue* getConstructor(KJS::ExecState*);
    enum {
        // Attributes
        IdentifierAttrNum, ListStyleAttrNum, SeparatorAttrNum, 

        // The Constructor Attribute
        ConstructorAttrNum
    };
    Counter* impl() const { return m_impl.get(); }

private:
    RefPtr<Counter> m_impl;
};

KJS::JSValue* toJS(KJS::ExecState*, Counter*);
Counter* toCounter(KJS::JSValue*);

class JSCounterPrototype : public KJS::JSObject {
public:
    static KJS::JSObject* self(KJS::ExecState*);
    virtual const KJS::ClassInfo* classInfo() const { return &s_info; }
    static const KJS::ClassInfo s_info;
    JSCounterPrototype(KJS::ExecState* exec)
        : KJS::JSObject(exec->lexicalGlobalObject()->objectPrototype()) { }
};

} // namespace WebCore

#endif
