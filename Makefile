#!/bin/bash

CP := cp
MKDIR := mkdir -p



install :
	sudo $(MKDIR) /usr/include/hpm
	sudo $(CP) include/*.h /usr/include/hpm/
