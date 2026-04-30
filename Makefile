CPPFLAGS	= -Wall -Werror -Wextra -MMD -MP -std=c++98
DEPS		= $(OBJS:.o=.d)

all: $(NAME)
-include $(DEPS)
