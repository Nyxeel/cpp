NAME		= megaphone
CXX			= g++
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98
MAKEFLAGS	+= --no-print-directory

OBJ_DIR		= objs

SRCS		= phonebook.cpp \

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# Farben
OK	= \033[38;5;76m
ERR	= \033[0;38;5;1m
HDR	= \033[1;36m
RST	= \033[0m

# FIXED BOX WIDTH (innenbreite = 46 chars)
# Wenn du breiter willst: mehr "─" hier.
TOP_EXEC	= ┌─[ EXECUTE ]──────────────────────────────────────┐
TOP_ALL     = ┌─[ ALL ]──────────────────────────────────────────┐
TOP_PREPARE = ┌─[ PREPARE ]──────────────────────────────────────┐
TOP_COMPILE = ┌─[ COMPILE ]──────────────────────────────────────┐
TOP_LINK    = ┌─[ LINK ]─────────────────────────────────────────┐
TOP_CLEAN   = ┌─[ CLEAN ]────────────────────────────────────────┐
TOP_FCLEAN  = ┌─[ FCLEAN ]───────────────────────────────────────┐
TOP_ERROR   = ┌─[ ERROR ]────────────────────────────────────────┐
BOT         = └──────────────────────────────────────────────────┘

# Innenbreite (muss zu den Linien oben passen!)
# Zähle Zeichen zwischen '│ ' und ' │' -> hier 50-?; wir setzen bewusst 50.
# Wenn du TOP/BOT änderst, diese Zahl mit anpassen.
W = 50

.ONESHELL:
SHELL := /bin/sh
.SILENT:

all:
	# Missing-Source-Check
	missing=false
	for src in $(SRCS); do
		if [ ! -f "$$src" ]; then
			printf "\n$(ERR)%s$(RST)\n" "$(TOP_ERROR)"
			printf "$(ERR)│ %-*s │$(RST)\n" 48 "Missing source file: $$src"
			printf "$(ERR)%s$(RST)\n\n" "$(BOT)"
			missing=true
		fi
	done
	if [ "$$missing" = true ]; then exit 1; fi

	if [ -f "$(NAME)" ]; then
		printf "\n$(OK)%s$(RST)\n" "$(TOP_ALL)"
		printf "$(OK)│ %-*s │$(RST)\n" $(W) "✔ Nothing to do (already built)"
		printf "$(OK)%s$(RST)\n\n" "$(BOT)"
	else
		$(MAKE) $(NAME)
	fi

$(NAME):

	# ASCII ART (vor PREPARE)
	@printf "$(HDR)"
	cat <<'ASCII'
	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠁⠀⡰⠀⠀⠀⠀⠀⠀⠀
	⠀⠀⠀⠀⠀⠀⠀⠀⢀⡎⢀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀
	⣀⠀⠀⠀⠀⠀⠀⡠⠬⡡⠬⡋⠀⡄⠀⠀⠀⠀⠀⠀⠀
	⡀⠁⠢⡀⠀⠀⢰⠠⢷⠰⠆⡅⠀⡇⠀⠀⠀⣀⠔⠂⡂
	⠱⡀⠀⠈⠒⢄⡸⡑⠊⢒⣂⣦⠄⢃⢀⠔⠈⠀⠀⡰⠁
	⠀⠱⡀⠀⠀⡰⣁⣼⡿⡿⢿⠃⠠⠚⠁⠀⠀⢀⠜⠀⠀
	⠀⠀⠐⢄⠜⠀⠈⠓⠒⠈⠁⠀⠀⠀⠀⠀⡰⠃⠀⠀⠀
	⠀⠀⢀⠊⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠾⡀⠀⠀⠀⠀
	⠀⠀⢸⣄⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡇⠀⠀⠀
	ASCII
	@printf "$(RST)"

	# PREPARE
	printf "\n$(HDR)%s$(RST)\n" "$(TOP_PREPARE)"
	if [ -d "$(OBJ_DIR)" ]; then
		printf "$(OK)│ %-*s │$(RST)\n" $(W) "📁 Using: $(OBJ_DIR)/"
	else
		if mkdir -p "$(OBJ_DIR)"; then
			printf "$(OK)│ %-*s │$(RST)\n" $(W) "📁 Created: $(OBJ_DIR)/"
		else
			printf "$(ERR)│ %-*s │$(RST)\n" $(W) "✘ Failed creating: $(OBJ_DIR)/"
			printf "$(HDR)%s$(RST)\n\n" "$(BOT)"
			exit 1
		fi
	fi
	printf "$(HDR)%s$(RST)\n" "$(BOT)"
	sleep 0.15

	# COMPILE (ein Rahmen, mehrere Zeilen)
	failed=false
	anything=false
	printf "\n$(HDR)%s$(RST)\n" "$(TOP_COMPILE)"
	for src in $(SRCS); do
		obj="$(OBJ_DIR)/$${src%.cpp}.o"
		if [ ! -f "$$obj" ] || [ "$$src" -nt "$$obj" ]; then
			if $(CXX) $(CPPFLAGS) -c "$$src" -o "$$obj"; then
				printf "$(OK)│ %-*s │$(RST)\n" $(W) "✔ $$obj"
				anything=true
				sleep 0.20
			else
				printf "$(ERR)│ %-*s │$(RST)\n" $(W) "✘ $$src"
				failed=true
				anything=true
				sleep 0.20
			fi
		fi
	done
	if [ "$$anything" = false ]; then
		printf "$(OK)│ %-*s │$(RST)\n" $(W) "✔ All objects up to date"
	fi
	printf "$(HDR)%s$(RST)\n" "$(BOT)"
	if [ "$$failed" = true ]; then printf "\n"; exit 1; fi
	sleep 0.10

	# LINK
	printf "\n$(HDR)%s$(RST)\n" "$(TOP_LINK)"

	link_output=$$( $(CXX) $(OBJS) -o "$(NAME)" 2>&1 )
	link_status=$$?

	if [ $$link_status -eq 0 ]; then
		printf "$(OK)│ %-*s │$(RST)\n" $(W) "✔ Compiled: $(NAME)"
		printf "$(HDR)%s$(RST)\n\n" "$(BOT)"
	else
		# WICHTIG: jede Zeile exakt mit "│ <padding> │" (inkl. beider Spaces)
		printf "$(ERR)│ %-*s │$(RST)\n" $(W) "✘ Link failed: $(NAME)"
		printf "$(ERR)│ %-*s │$(RST)\n" 48 ""

		# spezifische Fehler erkennen
		if echo "$$link_output" | grep -q "undefined reference"; then
			missing=$$(echo "$$link_output" | awk -F'`' '/undefined reference/ {print $$2; exit}')
			# optional: trailing ' entfernen
			missing=$$(printf "%s" "$$missing" | sed "s/'$$//")
			printf "$(ERR)│ %-*s │$(RST)\n" 48 "Missing symbol: $$missing"
		fi

		if echo "$$link_output" | grep -q "ld returned"; then
			printf "$(ERR)│ %-*s │$(RST)\n" 48 "Linker aborted build"
		fi

		printf "$(HDR)%s$(RST)\n\n" "$(BOT)"
		exit 1
	fi



RUN_ARGS := $(filter-out run,$(MAKECMDGOALS))

run: $(NAME)
	@printf "\n$(HDR)%s$(RST)\n" "$(TOP_EXEC)"
	@printf "$(OK)│ %-*.*s │$(RST)\n" 48 $(W) "./$(NAME) $(RUN_ARGS)"
	@printf "$(HDR)%s$(RST)\n\n" "$(BOT)"
	@./$(NAME) $(RUN_ARGS)

%:
	@:





clean:
	printf "\n$(HDR)%s$(RST)\n" "$(TOP_CLEAN)"
	if ls $(OBJS) >/dev/null 2>&1; then
		rm -f $(OBJS)
		printf "$(OK)│ %-*s │$(RST)\n" $(W) "✔ Removed objects from $(OBJ_DIR)/"
	else
		printf "$(ERR)│ %-*s │$(RST)\n" $(W) "⋗ No object files to clean"
	fi
	printf "$(HDR)%s$(RST)\n\n" "$(BOT)"

fclean:
	printf "\n$(HDR)%s$(RST)\n" "$(TOP_FCLEAN)"
	deleted=false
	if ls $(OBJS) >/dev/null 2>&1; then rm -f $(OBJS); deleted=true; fi
	if [ -f "$(NAME)" ]; then rm -f $(NAME); deleted=true; fi
	if [ -d "$(OBJ_DIR)" ]; then rm -rf $(OBJ_DIR); deleted=true; fi
	if [ "$$deleted" = true ]; then
		printf "$(OK)│ %-*s │$(RST)\n" $(W) "✔ Fully cleaned (objs + bin + dir)"
	else
		printf "$(ERR)│ %-*s │$(RST)\n" $(W) "⋗ Nothing to clean"
	fi
	printf "$(HDR)%s$(RST)\n\n" "$(BOT)"

re: fclean all

.PHONY: all clean fclean re
