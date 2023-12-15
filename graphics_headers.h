#ifndef GRAPHICS_HEADERS_H
#define GRAPHICS_HEADERS_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/ai_assert.h>
#include <assimp/aabb.h>
#include <assimp/mesh.h>
#include <assimp/AssertHandler.h>
#include <assimp/CreateAnimMesh.h>
#include <assimp/material.h>
#include <assimp/BaseImporter.h>
#include <assimp/Base64.hpp>
#include <assimp/anim.h>
#include <assimp/Bitmap.h>
#include <assimp/ByteSwapper.h>
#include <assimp/camera.h>
#include <assimp/cexport.h>
#include <assimp/cfileio.h>
#include <assimp/cimport.h>
#include <assimp/ColladaMetaData.h>
#include <assimp/color4.h>
#include <assimp/color4.inl>
#include <assimp/commonMetaData.h>
#include <assimp/config.h>
#include <assimp/DefaultIOStream.h>
#include <assimp/DefaultIOSystem.h>
#include <assimp/DefaultLogger.hpp>
#include <assimp/defs.h>
#include <assimp/Exceptional.h>
#include <assimp/Exporter.hpp>
#include <assimp/fast_atof.h>
#include <assimp/GenericProperty.h>
#include <assimp/GltfMaterial.h>
#include <assimp/Hash.h>
#include <assimp/importerdesc.h>
#include <assimp/IOStream.hpp>
#include <assimp/IOStreamBuffer.h>
#include <assimp/IOSystem.hpp>
#include <assimp/light.h>
#include <assimp/LineSplitter.h>
#include <assimp/LogAux.h>
#include <assimp/Logger.hpp>
#include <assimp/LogStream.hpp>
#include <assimp/material.h>
#include <assimp/material.inl>
#include <assimp/MathFunctions.h>
#include <assimp/matrix3x3.h>
#include <assimp/matrix3x3.inl>
#include <assimp/matrix4x4.h>
#include <assimp/matrix4x4.inl>
#include <assimp/MemoryIOWrapper.h>
#include <assimp/mesh.h>
#include <assimp/metadata.h>
#include <assimp/NullLogger.hpp>
#include <assimp/ObjMaterial.h>
#include <assimp/ParsingUtils.h>
#include <assimp/pbrmaterial.h>
#include <assimp/postprocess.h>
#include <assimp/Profiler.h>
#include <assimp/ProgressHandler.hpp>
#include <assimp/qnan.h>
#include <assimp/quaternion.h>
#include <assimp/quaternion.inl>
#include <assimp/RemoveComments.h>
#include <assimp/scene.h>
#include <assimp/SceneCombiner.h>
#include <assimp/SGSpatialSort.h>
#include <assimp/SkeletonMeshBuilder.h>
#include <assimp/SmallVector.h>
#include <assimp/SmoothingGroups.h>
#include <assimp/SmoothingGroups.inl>
#include <assimp/SpatialSort.h>
#include <assimp/StandardShapes.h>
#include <assimp/StreamReader.h>
#include <assimp/StreamWriter.h>
#include <assimp/StringComparison.h>
#include <assimp/StringUtils.h>
#include <assimp/Subdivision.h>
#include <assimp/texture.h>
#include <assimp/TinyFormatter.h>
#include <assimp/types.h>
#include <assimp/vector2.h>
#include <assimp/vector2.inl>
#include <assimp/vector3.h>
#include <assimp/vector3.inl>
#include <assimp/version.h>
//#include <assimp/XmlParser.h>
//#include <assimp/XMLTools.h>
#include <assimp/ZipArchiveIOSystem.h>


#define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#define GLM_ENABLE_EXPERIMENTAL 

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>

// GLM for matricies
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>

#define INVALID_UNIFORM_LOCATION 0x7fffffff

struct Vertex
{
	glm::vec3 vertex;
	glm::vec3 normal;
	glm::vec2 texcoord;

	Vertex(glm::vec3 v, glm::vec3 n, glm::vec2 tc) : vertex(v), normal(n), texcoord(tc) {}
};

#endif /* GRAPHICS_HEADERS_H */
