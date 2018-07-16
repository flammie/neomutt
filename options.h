/**
 * @file
 * Handling of global boolean variables
 *
 * @authors
 * Copyright (C) 2017 Richard Russon <rich@flatcap.org>
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

#ifndef _MUTT_OPTIONS_H_
#define _MUTT_OPTIONS_H_

#include <stdbool.h>
#include "where.h"

/* pseudo options */

WHERE bool OptAttachMsg;           /**< (pseudo) used by attach-message */
WHERE bool OptAuxSort;             /**< (pseudo) using auxiliary sort function */
WHERE bool OptDontHandlePgpKeys; /**< (pseudo) used to extract PGP keys */
WHERE bool OptForceRefresh;        /**< (pseudo) refresh even during macros */
WHERE bool OptIgnoreMacroEvents;  /**< (pseudo) don't process macro/push/exec events while set */
WHERE bool OptKeepQuiet;           /**< (pseudo) shut up the message and refresh functions while we are executing an external program.  */
WHERE bool OptMenuCaller;          /**< (pseudo) tell menu to give caller a take */
WHERE bool OptMsgErr;              /**< (pseudo) used by mutt_error/mutt_message */
WHERE bool OptNeedRescore;         /**< (pseudo) set when the `score' command is used */
WHERE bool OptNeedResort;          /**< (pseudo) used to force a re-sort */
#ifdef USE_NNTP
WHERE bool OptNews;                 /**< (pseudo) used to change reader mode */
WHERE bool OptNewsSend;            /**< (pseudo) used to change behavior when posting */
#endif
WHERE bool OptNoCurses;            /**< (pseudo) when sending in batch mode */
WHERE bool OptPgpCheckTrust;      /**< (pseudo) used by pgp_select_key () */
WHERE bool OptRedrawTree;          /**< (pseudo) redraw the thread tree */
WHERE bool OptResortInit;          /**< (pseudo) used to force the next resort to be from scratch */
WHERE bool OptSearchInvalid;       /**< (pseudo) used to invalidate the search pat */
WHERE bool OptSearchReverse;       /**< (pseudo) used by ci_search_command */
WHERE bool OptSignalsBlocked;      /**< (pseudo) using by mutt_block_signals () */
WHERE bool OptSortSubthreads;      /**< (pseudo) used when $sort_aux changes */
WHERE bool OptSysSignalsBlocked;  /**< (pseudo) using by mutt_block_signals_system () */
WHERE bool OptViewAttach;          /**< (pseudo) signals that we are viewing attachments */

#define mutt_bit_set(v, n)    v[n / 8] |= (1 << (n % 8))
#define mutt_bit_unset(v, n)  v[n / 8] &= ~(1 << (n % 8))
#define mutt_bit_toggle(v, n) v[n / 8] ^= (1 << (n % 8))
#define mutt_bit_isset(v, n)  (v[n / 8] & (1 << (n % 8)))

#endif /* _MUTT_OPTIONS_H_ */
