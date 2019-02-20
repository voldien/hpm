/**
    High performance matrix library utilizing SIMD extensions.
    Copyright (C) 2016  Valdemar Lindberg

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef _HPM_LOG_H_
#define _HPM_LOG_H_  1

enum HTP_VERBOSITY{
	HTP_VERBOSE_QUITE = 0,
	HTP_VERBOSE_LOG = 1,
	HTP_VERBOSE_DEBUG = 16,
};

/**
 *
 * @param verbosity
 */
extern void htpSetVerbosity(enum HTP_VERBOSITY verbosity);

/**
 *
 * @param level
 * @param format
 * @param ...
 * @return
 */
extern int htpLogPrint(enum HTP_VERBOSITY level, const char* format,...);

#endif