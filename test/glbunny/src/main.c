#include "Bunny.h"
#include "glbunny.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <assert.h>
#include <getopt.h>
#include <hpm.h>

int main(int argc, const char **argv) {

	/*	Read user argument.	*/
	readargument(argc, argv);

	/*	Print dependency library versions.*/
	print_dependency_versions();

	/*	Initialize hpm library.	*/
	if (hpm_init(g_hpmflag) == 0) {
		fprintf(stderr, "Failed to initialize HPM, %x - %s.\n", g_hpmflag, hpm_get_simd_symbol(g_hpmflag));
		return EXIT_FAILURE;
	}

	/*  Allocate scene. */
	Scene *scene = malloc(sizeof(Scene));
	memset(scene, 0, sizeof(Scene));

	/*  Create scene.   */
	if (!createScene(scene)) {
		return EXIT_FAILURE;
	}

	/*  Renderer scene.   */
	sceneRenderer(scene);

	/*  Release all resources.  */
	releaseScene(scene);
	free(scene);
	return EXIT_SUCCESS;
}
