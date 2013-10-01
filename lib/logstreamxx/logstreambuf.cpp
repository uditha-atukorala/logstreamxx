/*
*  logstreamxx - C++ logging library based on standard stream classes
*  Copyright (C) 2013 Uditha Atukorala
*
*  This software library is free software; you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation; either version 3 of the License, or
*  (at your option) any later version.
*
*  This software library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public License
*  along with this software library. If not, see <http://www.gnu.org/licenses/>.
*
*/

#include "logstreambuf.h"

#include <unistd.h>


namespace logstreamxx {

	logstreambuf::logstreambuf() : _fd( STDOUT_FILENO ), _continue( false ) {

		size_t _bufsize = 10;

		// allocate output buffer space
		char * pbuf = new char[_bufsize];

		// setup output buffer
		setp( pbuf, pbuf + ( _bufsize - 1 ) );

	}


	logstreambuf::~logstreambuf() {

		// sync
		sync();

		// cleanup output buffer
		delete [] pbase();

	}


	int logstreambuf::flush() {

		int flush_size = pptr() - pbase();

		// sanity check - is there anything to flush?
		if ( flush_size > 0 ) {

			// write prefix
			if ( wprefix() ) {

				//  write buffer content
				if ( write( _fd, pbase(), flush_size ) == flush_size ) {
					pbump( -flush_size );
					return flush_size;
				}

			}

		}

		return traits_type::eof();

	}


	bool logstreambuf::wprefix() {

		// check - do we need to write the prefix
		if (! _continue ) {

			// write prefix
			if ( write( _fd, "-prefix- ", 9 ) != 9 ) {
				return false;
			}

		}

		// update continuation flag
		_continue = true;

		return true;

	}


	int logstreambuf::overflow( int c ) {

		if ( c != traits_type::eof() ) {

			// insert the overflowed char into the buffer
			*pptr() = c;
			pbump( 1 );

		}

		if ( flush() == traits_type::eof() ) {
			return traits_type::eof();
		}

		return c;

	}


	int logstreambuf::sync() {

		// flush buffer
		if ( flush() == traits_type::eof() ) {
			return traits_type::eof();
		}

		// update continuation flag
		_continue = false;

		return 0;

	}

} /* end of namespace logstreamxx */

