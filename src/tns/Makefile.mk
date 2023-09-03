#  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
#  SPDX-License-Identifier: MIT

#  WARNING: this makefile is intended to be included. DO NOT USE!

SRC=tns_new.c tns_setget.c tns_cpy.c tns_matmul.c tns_softmax.c 
HDR=tns_utils.h tns_types.h tns_new.h tns_setget.h tns_cpy.h tns_matmul.h tns_softmax.h

HDR_F=$(addprefix $(SRCDIR)/tns/,$(HDR))
SRC_F=$(addprefix $(SRCDIR)/tns/,$(SRC))

$(SRCDIR)/tns.c: $(SRC_F) $(SRCDIR)/tns.h
	@cat $(SRCDIR)/tns/tns.c.start > $(SRCDIR)/tns.c
	@for f in $(SRC_F); do cat $$f >> $(SRCDIR)/tns.c ; done
	@echo "tns.c created"

$(SRCDIR)/tns.h: $(HDR_F)
	@cat $(SRCDIR)/tns/tns.h.start > $(SRCDIR)/tns.h
	@for f in $(HDR_F); do echo "\n#line 1 \"$$f\"" >> $(SRCDIR)/tns.h; cat $ $$f >> $(SRCDIR)/tns.h ; done
	@echo "\n#endif" >> $(SRCDIR)/tns.h
	@echo "tns.h created"
