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

#ifndef JSDOMSelection_h
#define JSDOMSelection_h

#include "JSDOMBinding.h"
#include <kjs/JSGlobalObject.h>
#include <kjs/ObjectPrototype.h>

namespace WebCore {

class DOMSelection;

class JSDOMSelection : public DOMObject {
    typedef DOMObject Base;
public:
    JSDOMSelection(KJS::JSObject* prototype, DOMSelection*);
    virtual ~JSDOMSelection();
    virtual bool getOwnPropertySlot(KJS::ExecState*, const KJS::Identifier& propertyName, KJS::PropertySlot&);
    KJS::JSValue* getValueProperty(KJS::ExecState*, int token) const;
    virtual const KJS::ClassInfo* classInfo() const { return &s_info; }
    static const KJS::ClassInfo s_info;

    enum {
        // Attributes
        AnchorNodeAttrNum, AnchorOffsetAttrNum, FocusNodeAttrNum, FocusOffsetAttrNum, 
        BaseNodeAttrNum, BaseOffsetAttrNum, ExtentNodeAttrNum, ExtentOffsetAttrNum, 
        IsCollapsedAttrNum, TypeAttrNum, RangeCountAttrNum, 
    };
    DOMSelection* impl() const { return m_impl.get(); }

private:
    RefPtr<DOMSelection> m_impl;
};

KJS::JSValue* toJS(KJS::ExecState*, DOMSelection*);
DOMSelection* toDOMSelection(KJS::JSValue*);

class JSDOMSelectionPrototype : public KJS::JSObject {
public:
    static KJS::JSObject* self(KJS::ExecState*);
    virtual const KJS::ClassInfo* classInfo() const { return &s_info; }
    static const KJS::ClassInfo s_info;
    bool getOwnPropertySlot(KJS::ExecState*, const KJS::Identifier&, KJS::PropertySlot&);
    JSDOMSelectionPrototype(KJS::ExecState* exec)
        : KJS::JSObject(exec->lexicalGlobalObject()->objectPrototype()) { }
};

// Functions

KJS::JSValue* jsDOMSelectionPrototypeFunctionCollapse(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionCollapseToEnd(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionCollapseToStart(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionDeleteFromDocument(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionContainsNode(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionSelectAllChildren(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionEmpty(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionSetBaseAndExtent(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionSetPosition(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionModify(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionExtend(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionGetRangeAt(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionRemoveAllRanges(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionAddRange(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
KJS::JSValue* jsDOMSelectionPrototypeFunctionToString(KJS::ExecState*, KJS::JSObject*, KJS::JSValue*, const KJS::ArgList&);
} // namespace WebCore

#endif
