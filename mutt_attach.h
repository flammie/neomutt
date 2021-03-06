/**
 * @file
 * Handling of email attachments
 *
 * @authors
 * Copyright (C) 1996-2000 Michael R. Elkins <me@mutt.org>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* common protos for compose / attach menus */

#ifndef MUTT_MUTT_ATTACH_H
#define MUTT_MUTT_ATTACH_H

#include <stdbool.h>
#include <stdio.h>

struct AttachCtx;
struct Menu;
struct Header;
struct Body;

int mutt_tag_attach(struct Menu *menu, int n, int m);
int mutt_attach_display_loop(struct Menu *menu, int op, struct Header *hdr,
                             struct AttachCtx *actx, bool recv);

void mutt_save_attachment_list(struct AttachCtx *actx, FILE *fp, bool tag,
                               struct Body *top, struct Header *hdr, struct Menu *menu);
void mutt_pipe_attachment_list(struct AttachCtx *actx, FILE *fp, bool tag,
                               struct Body *top, bool filter);
void mutt_print_attachment_list(struct AttachCtx *actx, FILE *fp, bool tag,
                                struct Body *top);

int mutt_view_attachment(FILE *fp, struct Body *a, int flag, struct Header *hdr, struct AttachCtx *actx);

void mutt_check_lookup_list(struct Body *b, char *type, size_t len);
int mutt_compose_attachment(struct Body *a);
int mutt_decode_save_attachment(FILE *fp, struct Body *m, char *path, int displaying, int flags);
int mutt_edit_attachment(struct Body *a);
int mutt_get_tmp_attachment(struct Body *a);
int mutt_pipe_attachment(FILE *fp, struct Body *b, const char *path, char *outfile);
int mutt_print_attachment(FILE *fp, struct Body *a);
int mutt_save_attachment(FILE *fp, struct Body *m, char *path, int flags, struct Header *hdr);

#endif /* MUTT_MUTT_ATTACH_H */
