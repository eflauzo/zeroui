
EMCC = emcc
SOURCES = core.c zeroui.c zeroui_canvas_sdl.c zeroui_common.c zeroui_context.c zeroui_typograph.c zeroui_controls.c zeroui_list.c zeroui_select_bf.c zeroui_mempool.c
SOURCES_EXTRA = console.c

EMFLAGS := $(EMFLAGS) -s WASM=1 -s USE_SDL=2 -O3

build: $(SOURCES)
		$(EMCC) $(EMFLAGS) $(SOURCES) -o zeroui_test.js

binary: $(SOURCES) $(SOURCES_EXTRA)
		$(CC) $(SOURCES) $(SOURCES_EXTRA) -o zeroui_test

test:
		xdg-open 'http://localhost:8888/index.html'
