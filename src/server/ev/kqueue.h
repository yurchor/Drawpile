/*******************************************************************************

   Copyright (C) 2007 M.K.A. <wyrmchild@users.sourceforge.net>
   
   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:
   
   Except as contained in this notice, the name(s) of the above copyright
   holders shall not be used in advertising or otherwise to promote the sale,
   use or other dealings in this Software without prior written authorization.
   
   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.

*******************************************************************************/

#ifndef EventKqueue_INCLUDED
#define EventKqueue_INCLUDED

#include "interface.h"
#include "traits.h"

#ifndef NDEBUG
	#include <iostream>
	using std::cout;
	using std::endl;
#endif

#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>

class EventKqueue
	: EventInterface<int>
{
private:
	timespec _timeout;
	int nfds;
	kevent chlist[max_events], *evtrigr;
	size_t chlist_count, evtrigr_size;
public:
	static const int read, write;
	
	EventKqueue() throw();
	~EventKqueue() throw();
	
	void timeout(uint msecs) throw();
	int wait() throw();
	int add(fd_t fd, int events) throw();
	int remove(fd_t fd) throw();
	int modify(fd_t fd, int events) throw();
	bool getEvent(fd_t &fd, int &events) throw();
};

template <>
struct EventTraits<EventKqueue>
{
	typedef int ev_t;
	
	static const bool hasHangup = false;
	static const bool hasError = false;
	static const bool hasAccept = false;
	static const bool hasConnect = false;
	static const bool usesSigmask = false;
};

#endif // EventKqueue_INCLUDED