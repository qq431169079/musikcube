//////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2007-2016 musikcube team
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright notice,
//      this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the author nor the names of other contributors may
//      be used to endorse or promote products derived from this software
//      without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "OutputWindow.h"

#include <cursespp/Screen.h>
#include <cursespp/Colors.h>
#include <cursespp/MultiLineEntry.h>

using namespace musik::box;
using namespace cursespp;

typedef IScrollAdapter::EntryPtr EntryPtr;

OutputWindow::OutputWindow(IWindow *parent)
: ScrollableWindow(parent) {
    this->SetContentColor(BOX_COLOR_BLACK_ON_GREY);
    this->adapter = new SimpleScrollAdapter();
    this->adapter->SetDisplaySize(this->GetContentWidth(), this->GetContentHeight());
    this->adapter->SetMaxEntries(500);
}

OutputWindow::~OutputWindow() {

}

IScrollAdapter& OutputWindow::GetScrollAdapter() {
    return (IScrollAdapter&) *this->adapter;
}

void OutputWindow::WriteLine(const std::string& text, int64 attrs) {
    this->adapter->AddEntry(EntryPtr(new MultiLineEntry(text, attrs)));
    this->OnAdapterChanged();
}
