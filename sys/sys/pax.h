/*-
 * Copyright (c) 2006 Elad Efrat <elad@NetBSD.org>
 * Copyright (c) 2013-2014, by Oliver Pinter <oliver.pntr at gmail.com>
 * Copyright (c) 2014, by Shawn Webb <lattera at gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef	__SYS_PAX_H
#define	__SYS_PAX_H

#ifdef _KERNEL

struct image_params;
struct prison;
struct thread;
struct proc;
struct vnode;
struct vmspace;
struct vm_offset_t;

/*
 * used in sysctl handler
 */
#define	PAX_FEATURE_DISABLED		0
#define	PAX_FEATURE_OPTIN		1
#define	PAX_FEATURE_OPTOUT		2
#define	PAX_FEATURE_FORCE_ENABLED	3
#define	PAX_FEATURE_UNKNOWN_STATUS	4

extern const char *pax_status_str[];

#define PAX_FEATURE_SIMPLE_DISABLED	0
#define PAX_FEATURE_SIMPLE_ENABLED	1

extern const char *pax_status_simple_str[];

extern int pax_aslr_status;

extern int pax_aslr_mmap_len;
extern int pax_aslr_stack_len;
extern int pax_aslr_exec_len;
#ifdef COMPAT_FREEBSD32
extern int pax_aslr_compat_status;
extern int pax_aslr_compat_mmap_len;
extern int pax_aslr_compat_stack_len;
extern int pax_aslr_compat_exec_len;
#endif /* COMPAT_FREEBSD32 */

/*
 * generic pax functions
 */
int pax_elf(struct image_params *, uint32_t);
#ifdef PAX_SEGVGUARD
extern int pax_segvguard_status;
extern int pax_segvguard_debug;
extern int pax_segvguard_expiry;
extern int pax_segvguard_suspension;
extern int pax_segvguard_maxcrashes;
#endif /* PAX_SEGVGUARD */

#ifdef PAX_HARDENING
extern int pax_map32_enabled_global;
#endif /* PAX_HARDENING*/

extern int pax_log_log;
extern int pax_log_ulog;

#define PAX_LOG_LOG		0
#define PAX_LOG_ULOG		0

#define PAX_SEGVGUARD_EXPIRY        (2 * 60)
#define PAX_SEGVGUARD_SUSPENSION    (10 * 60)
#define PAX_SEGVGUARD_MAXCRASHES    5

void pax_init_prison(struct prison *pr);
void pax_get_flags(struct proc *p, uint32_t *flags);
struct prison *pax_get_prison(struct proc *p);
void pax_init_prison(struct prison *pr);

/*
 * ASLR related functions
 */
int pax_aslr_active(struct proc *p);
void pax_aslr_init_vmspace(struct proc *p);
void pax_aslr_init_vmspace32(struct proc *p);
void pax_aslr_init(struct image_params *imgp);
void pax_aslr_mmap(struct proc *p, vm_offset_t *addr, 
    vm_offset_t orig_addr, int flags);
u_int pax_aslr_setup_flags(struct image_params *imgp, u_int mode);
void pax_aslr_stack(struct proc *p, uintptr_t *addr);

#endif /* _KERNEL */

#define ELF_NOTE_TYPE_PAX_TAG   3
#define PAX_NOTE_MPROTECT   0x01
#define PAX_NOTE_NOMPROTECT 0x02
#define PAX_NOTE_GUARD      0x04
#define PAX_NOTE_NOGUARD    0x08
#define PAX_NOTE_ASLR       0x10
#define PAX_NOTE_NOASLR     0x20

#define PAX_NOTE_ALL_ENABLED	\
			(PAX_NOTE_MPROTECT | PAX_NOTE_GUARD | PAX_NOTE_ASLR)
#define PAX_NOTE_ALL_DISABLED	\
			(PAX_NOTE_NOMPROTECT | PAX_NOTE_NOGUARD | PAX_NOTE_NOASLR)
#define PAX_NOTE_ALL	(PAX_NOTE_ALL_ENABLED | PAX_NOTE_ALL_DISABLED)

#endif /* __SYS_PAX_H */
