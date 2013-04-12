/* -*- mode: c; c-basic-offset: 4 -*- */
/*
 * Copyright (C) 2006 Apple Computer, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

/*
* This file was modified by Electronic Arts Inc Copyright � 2009-2010
*/

#ifndef Node_h
#define Node_h

#include <wtf/FastAllocBase.h>
typedef struct __Node Node;
typedef struct __NodeLink NodeLink;

struct __NodeLink/*: public WTF::FastAllocBase*/ {
    Node* node;
    NodeLink* prev;
};

struct __Node/*: public WTF::FastAllocBase*/ {
    unsigned refCount;
    const char* nodeType;
    NodeLink* childNodesTail;
};

extern Node* Node_new(void);
extern void Node_ref(Node* node);
extern void Node_deref(Node* node);
extern void Node_appendChild(Node* node, Node* child);
extern void Node_removeChild(Node* node, Node* child);
extern void Node_replaceChild(Node* node, Node* newChild, Node* oldChild);

#endif /* Node_h */
