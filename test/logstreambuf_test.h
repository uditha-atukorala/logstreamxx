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

#ifndef LOGSTREAMBUF_TEST_H
#define LOGSTREAMBUF_TEST_H

#include <cppunit/extensions/HelperMacros.h>


class logstreambuf_test : public CppUnit::TestFixture {

	// setup the test suite
	CPPUNIT_TEST_SUITE( logstreambuf_test );
	CPPUNIT_TEST( test_constructor );
	CPPUNIT_TEST( test_overloaded_constructor );
	CPPUNIT_TEST( test_overloaded_constructor_fail );
	CPPUNIT_TEST( test_lpriority );
	CPPUNIT_TEST( test_setlogmask );
	CPPUNIT_TEST( test_setlogmask_complex );
	CPPUNIT_TEST( test_lprefix );
	CPPUNIT_TEST_SUITE_END();

public:

	void test_constructor();
	void test_overloaded_constructor();
	void test_overloaded_constructor_fail();
	void test_lpriority();
	void test_setlogmask();
	void test_setlogmask_complex();
	void test_lprefix();

};

#endif

