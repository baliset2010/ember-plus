#!/bin/sh

#cmake ..

gcc -g \
   	-I/home/toshi/dev/ember-plus/libember_slim/Source \
   	__sample.c \
	__sample_consumer.c \
	__sample_provider.c \
	libember_slim-static.a \
	-o ember-plus_linux_libember-slim_sample \
	-lpthread

