/*
 * $Id$
 *
 * timer related functions
 *
 * Copyright (C) 2001-2003 FhG Fokus
 * Copyright (C) 2007 Voice Sistem SRL
 *
 * This file is part of openser, a free SIP server.
 *
 * openser is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * openser is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 * --------
 *  2007-02-02  timer with resolution of microseconds added (bogdan)
 */



#ifndef timer_h
#define timer_h

typedef unsigned long long utime_t;

typedef void (timer_function)(unsigned int ticks, void* param);
typedef void (utimer_function)(utime_t uticks, void* param);



struct sr_timer{
	int id;
	union {
		timer_function* timer_f;
		utimer_function* utimer_f;
	}u;
	void* t_param;
	unsigned int interval;
	
	utime_t expires;
	
	struct sr_timer* next;
};



int init_timer();

void destroy_timer();

int has_timers();

void run_timer();

/*register a periodic timer;
 * ret: <0 on error*/
int register_timer(timer_function f, void* param, unsigned int interval);

int register_utimer(utimer_function f, void* param, unsigned int interval);

unsigned int get_ticks();

utime_t get_uticks();

#endif
