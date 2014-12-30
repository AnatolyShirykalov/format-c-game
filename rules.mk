
OBJS=$(SOURCES:%.c=$(OBJDIR)/%.o)




clean:
	rm -rf $(OBJDIR) $(PROG_NAME) data.res
Clean:
	rm *~


ifneq ($(MAKECMDGOALS),clean)
-include $(SOURCES:%.c=$(OBJDIR)/%.d)
endif

$(OBJDIR)/%.d: %.c
	mkdir -p $(OBJDIR) $(OBJDIR)/rooms
	$(CC) -MM -MF $@ -E $< -MT '$@ $(OBJDIR)/$*.o' $(CFLAGS)

$(OBJDIR)/%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
