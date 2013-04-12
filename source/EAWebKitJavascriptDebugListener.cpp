/*
Copyright (C) 2011 Electronic Arts, Inc.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1.  Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
2.  Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
3.  Neither the name of Electronic Arts, Inc. ("EA") nor the names of
    its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY ELECTRONIC ARTS AND ITS CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ELECTRONIC ARTS OR ITS CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

///////////////////////////////////////////////////////////////////////////////
// EAWebKitJavascriptDebugger.cpp
// By David Siems
///////////////////////////////////////////////////////////////////////////////

#include <EAWebKit/EAWebKitJavascriptDebugListener.h>
#include <EAWebKit/internal/EAWebKitJavascriptDebugger.h>
#include <EAWebKit/internal/EAWebKitAssert.h>
#include <EAWebKit/internal/EAWebkitEASTLHelpers.h>
#include <EAWebKit/EAWebKitView.h>

#include "Webcore/Page/Page.h"
#include "JavaScriptCore/kjs/JSGlobalObject.h"

namespace EA { namespace WebKit {

EAWebKitJavascriptDebuggerWrapper::EAWebKitJavascriptDebuggerWrapper(void)
: mDebugger(NULL) {
    // Do nothing.
}

void EAWebKitJavascriptDebuggerWrapper::Attach(EAWebKitJavascriptDebugListener *listener) {
    if (!mDebugger) {
        mDebugger = EAWEBKIT_NEW("EAWebKitJavascriptDebugger") EAWebKitJavascriptDebugger();
    }

    if (GetViewCount() > 0) {
        WebCore::Page::setDebuggerForAllPages(mDebugger);
    }

    mDebugger->SetListener(listener);
}

void EAWebKitJavascriptDebuggerWrapper::Detach(void) {
    if (mDebugger) {
        if (GetViewCount() > 0) {
            WebCore::Page::setDebuggerForAllPages(NULL);
        }

        EAWEBKIT_DELETE mDebugger;
        mDebugger = NULL;
    }
}

const char *EAWebKitJavascriptDebuggerWrapper::IdToFile(int sourceId) {
    EAW_ASSERT(mDebugger);
    return mDebugger->IdToFile(sourceId);
}

int EAWebKitJavascriptDebuggerWrapper::FileToId(const char *filename, unsigned line) {
    EAW_ASSERT(mDebugger);
    return mDebugger->FileToId(filename, line);
}

bool EAWebKitJavascriptDebuggerWrapper::EvaluateExpression(const char *expression, JavascriptValue *resultOut) {
    EAW_ASSERT(mDebugger);
    return mDebugger->EvaluateExpression(expression, resultOut);
}

int EAWebKitJavascriptDebuggerWrapper::GetCurrentLine(void) {
    EAW_ASSERT(mDebugger);
    return mDebugger->GetCurrentLine();
}

const char *EAWebKitJavascriptDebuggerWrapper::GetCurrentFile(void) {
    EAW_ASSERT(mDebugger);
    return mDebugger->GetCurrentFile();
}

void EAWebKitJavascriptDebugListener::SetDebugWrapper(EAWebKitJavascriptDebuggerWrapper *wrapper) {
    mDebuggerWrapper = wrapper;
}

EAWebKitJavascriptDebuggerWrapper *EAWebKitJavascriptDebugListener::GetDebugWrapper(void) {
    return mDebuggerWrapper;
}

bool EAWebKitJavascriptDebuggerWrapper::GetCallFrame(EAWebkitJavascriptCallFrameWrapper *wrapper) {
    WebCore::JavaScriptCallFrame *frame = mDebugger->GetCallFrame();

    if (frame) {
        wrapper->mFrame = EAWEBKIT_NEW("EAWebkitCallFrame") EAWebkitJavascriptCallFrame();
        wrapper->mFrame->mCallFrame = frame;
        wrapper->mDebugWrapper = this;
        return true;
    }
    
    return false;
}

void EAWebKitJavascriptDebuggerWrapper::CleanupCallFrame(EAWebkitJavascriptCallFrameWrapper *wrapper) {
    EAWEBKIT_DELETE wrapper->mFrame;
    wrapper->mFrame = NULL;
    wrapper->mDebugWrapper = NULL;
}

void EAWebKitJavascriptDebuggerWrapper::AddPage(void *page) {
    WebCore::Page *webcorePage = reinterpret_cast<WebCore::Page*>(page);
    webcorePage->setDebugger(mDebugger);
}

void EAWebKitJavascriptDebugListener::Attach(void) {
    if (mDebuggerWrapper) {
        mDebuggerWrapper->Attach(this);
    }
}

void EAWebKitJavascriptDebugListener::Detach(void) {
    if (mDebuggerWrapper) {
        mDebuggerWrapper->Detach();
    }
}

void EAWebKitJavascriptDebugListener::AddPage(void *page) {
    if (mDebuggerWrapper) {
        mDebuggerWrapper->AddPage(page);
    }
}

const char16_t *EAWebKitJavascriptDebuggerWrapper::FunctionName(EAWebkitJavascriptCallFrame *callframe) {
    WebCore::JavaScriptCallFrame *frame = reinterpret_cast<WebCore::JavaScriptCallFrame*>(callframe->mCallFrame);
    WebCore::String name = frame->functionName();
    
    FixedString16_128 *nameOut = GetFixedString(callframe->mName);
    nameOut->assign(name.characters(), name.length());

    return nameOut->data();
}

EASTLVectorJavaScriptValueWrapper *EAWebKitJavascriptDebuggerWrapper::ScopeChain(EAWebkitJavascriptCallFrame *callframe) {
    WebCore::JavaScriptCallFrame *frame = reinterpret_cast<WebCore::JavaScriptCallFrame*>(callframe->mCallFrame);
    VectorJavaScriptValue *chainOut = GetVectorJavaScriptValue(callframe->mScopeChain);
    chainOut->clear();

    JavascriptObjectStore store;
    const KJS::ScopeChainNode *scopeChain = frame->scopeChain();
    while (scopeChain != NULL) {
        chainOut->push_back(JavascriptValue());
        TranslateJSValue(scopeChain->object, &chainOut->back(), scopeChain->globalObject()->globalExec(), &store);

        scopeChain = scopeChain->next;
    }

    return &callframe->mScopeChain;
}

bool EAWebKitJavascriptDebuggerWrapper::Caller(EAWebkitJavascriptCallFrame *callframe, EAWebkitJavascriptCallFrameWrapper *wrapperOut) {
    WebCore::JavaScriptCallFrame *frame = callframe->mCallFrame->caller();
    if (frame) {
        wrapperOut->mFrame = EAWEBKIT_NEW("EAWebkitCallFrame") EAWebkitJavascriptCallFrame();
        wrapperOut->mFrame->mCallFrame = frame;
        wrapperOut->mDebugWrapper = this;
        return true;
    }

    return false;
}

}}
