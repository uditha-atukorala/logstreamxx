## [logstreamxx] src/

AM_CPPFLAGS             = -I$(top_srcdir)/lib

noinst_PROGRAMS         = stdout_logger file_logger

stdout_logger_SOURCES   = stdout_logger.cpp
stdout_logger_LDADD     = -L$(top_builddir)/lib/logstreamxx -llogstreamxx

file_logger_SOURCES     = file_logger.cpp
file_logger_LDADD       = -L$(top_builddir)/lib/logstreamxx -llogstreamxx

