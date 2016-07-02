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

#pragma once

#include "curses_config.h"

#define CURSESPP_SELECTED_LIST_ITEM 1
#define CURSESPP_HIGHLIGHTED_LIST_ITEM 2
#define CURSESPP_HIGHLIGHTED_SELECTED_LIST_ITEM 3
#define CURSESPP_LIST_ITEM_HEADER 4

#define CURSESPP_DEFAULT_CONTENT_COLOR 5
#define CURSESPP_DEFAULT_FRAME_COLOR 6
#define CURSESPP_FOCUSED_FRAME_COLOR 7

#define CURSESPP_TEXT_DEFAULT 8
#define CURSESPP_TEXT_DISABLED 9
#define CURSESPP_TEXT_FOCUSED 10
#define CURSESPP_TEXT_ACTIVE 11
#define CURSESPP_TEXT_WARNING 12
#define CURSESPP_TEXT_ERROR 13
#define CURSESPP_TEXT_HIDDEN 14

namespace cursespp {
    class Colors {
        private:
            Colors();

        public:
            static void Init();
    };
}
