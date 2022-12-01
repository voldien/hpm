#include "glbunny.h"
#include <GL/glew.h>

void callback_debug_gl(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message,
					   GLvoid *userParam) {

	char *sourceString;
	char *typeString;
	char *severityString;

	switch (source) {
	case GL_DEBUG_CATEGORY_API_ERROR_AMD:
	case GL_DEBUG_SOURCE_API: {
		sourceString = "API";
		break;
	}
	case GL_DEBUG_CATEGORY_APPLICATION_AMD:
	case GL_DEBUG_SOURCE_APPLICATION: {
		sourceString = "Application";
		break;
	}
	case GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD:
	case GL_DEBUG_SOURCE_WINDOW_SYSTEM: {
		sourceString = "Window System";
		break;
	}
	case GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD:
	case GL_DEBUG_SOURCE_SHADER_COMPILER: {
		sourceString = "Shader Compiler";
		break;
	}
	case GL_DEBUG_SOURCE_THIRD_PARTY: {
		sourceString = "Third Party";
		break;
	}
	case GL_DEBUG_CATEGORY_OTHER_AMD:
	case GL_DEBUG_SOURCE_OTHER: {
		sourceString = "Other";
		break;
	}
	default: {
		sourceString = "Unknown";
		break;
	}
	} /**/
	printf("%s", sourceString);

	switch (type) {
	case GL_DEBUG_TYPE_ERROR: {
		typeString = "Error";
		break;
	}
	case GL_DEBUG_CATEGORY_DEPRECATION_AMD:
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: {
		typeString = "Deprecated Behavior";
		break;
	}
	case GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD:
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: {
		typeString = "Undefined Behavior";
		break;
	}
	case GL_DEBUG_TYPE_PORTABILITY_ARB: {
		typeString = "Portability";
		break;
	}
	case GL_DEBUG_CATEGORY_PERFORMANCE_AMD:
	case GL_DEBUG_TYPE_PERFORMANCE: {
		typeString = "Performance";
		break;
	}
	case GL_DEBUG_CATEGORY_OTHER_AMD:
	case GL_DEBUG_TYPE_OTHER: {
		typeString = "Other";
		break;
	}
	default: {
		typeString = "Unknown";
		break;
	}
	} /**/
	printf("%s", typeString);

	switch (severity) {
	case GL_DEBUG_SEVERITY_HIGH: {
		severityString = "High";
		break;
	}
	case GL_DEBUG_SEVERITY_MEDIUM: {
		severityString = "Medium";
		break;
	}
	case GL_DEBUG_SEVERITY_LOW: {
		severityString = "Low";
		break;
	}
	default: {
		severityString = "Unknown";
		break;
	}
	} /**/
	printf("%s", severityString);

	printf("%s", message);
	printf("\n");
}

void enableGLDebug(void) {

	/*	Check if debug callback is supported.	*/
	if (!glDebugMessageCallbackAMD && !glDebugMessageCallbackARB) {
		fprintf(stderr, "Failed loading OpenGL callback functions.\n");
		return;
	}

	/*	Set Debug message callback.	*/
	if (glDebugMessageCallbackARB) {
		glDebugMessageCallbackARB((GLDEBUGPROCARB)callback_debug_gl, NULL);
	}
	if (glDebugMessageCallbackAMD) {
		glDebugMessageCallbackAMD((GLDEBUGPROCAMD)callback_debug_gl, NULL);
	}

	/*	Enable debug.    */
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
}
