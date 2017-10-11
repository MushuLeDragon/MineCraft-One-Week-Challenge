#include "WaterRenderer.h"

#include "../World/Chunk/ChunkMesh.h"
#include "../World/Block/BlockDatabase.h"
#include "../Application.h"
#include "../Camera.h"
#include "../Sky/SkyManager.h"

#include <iostream>

void WaterRenderer::add(const ChunkMesh& mesh)
{
    m_chunks.push_back(&mesh);
}

void WaterRenderer::render(const Camera& camera, Config* conf)
{
    if (m_chunks.empty())
    {
        return;
    }

    glEnable(GL_BLEND);
    glDisable(GL_CULL_FACE);
    m_shader.useProgram();

    m_shader.loadProjectionViewMatrix(camera.getProjectionViewMatrix());
    m_shader.loadTime(g_timeElapsed);
<<<<<<< HEAD
    m_shader.loadLighting(g_light);
    
=======

>>>>>>> f3e97e016195af4996ca915e5d58c4322ad581d1
    for (const auto& mesh : m_chunks)
    {
        mesh->getModel().bindVAO();
        GL::drawElements(mesh->getModel().getIndicesCount());
    }

    m_chunks.clear();
}
