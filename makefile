all :
	gcc hypnosis.c -lraylib -o hypnosis
	# -lraylib -lopengl32 -lgdi32 -lwinmm -o main.exe
run :
	./hypnosis
