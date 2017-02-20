#include "MeshBuilder.h"
#include <GL\glew.h>
#include <vector>
#include "Vertex.h"
#include "MyMath.h"
#include "LoadOBJ.h"

/******************************************************************************/
/*!
\brief
Generate the vertices of a reference Axes; Use red for x-axis, green for y-axis, blue for z-axis
Then generate the VBO/IBO and store them in Mesh object

\param meshName - name of mesh
\param lengthX - x-axis should start at -lengthX / 2 and end at lengthX / 2
\param lengthY - y-axis should start at -lengthY / 2 and end at lengthY / 2
\param lengthZ - z-axis should start at -lengthZ / 2 and end at lengthZ / 2

\return Pointer to mesh storing VBO/IBO of reference axes
*/
/******************************************************************************/
Mesh* MeshBuilder::GenerateAxes(const std::string &meshName, float lengthX, float lengthY, float lengthZ)
{
	Vertex v;
	std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
	std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

	v.pos.Set(-1000, 0, 0); v.color.Set(1, 0, 0); v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(1000, 0, 0); v.color.Set(1, 0, 0); v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);

	v.pos.Set(0, -1000, 0); v.color.Set(0, 1, 0); v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(0, 1000, 0); v.color.Set(0, 1, 0); v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);

	v.pos.Set(0, 0, -1000); v.color.Set(0, 0, 1); v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(0, 0, 10000); v.color.Set(0, 0, 1); v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);

	for (unsigned i = 0; i < 6; ++i)
	{
		index_buffer_data.push_back(i);
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_LINES;

	return mesh;
}

/******************************************************************************/
/*!
\brief
Generate the vertices of a quad; Use random color for each vertex
Then generate the VBO/IBO and store them in Mesh object

\param meshName - name of mesh
\param lengthX - width of quad
\param lengthY - height of quad

\return Pointer to mesh storing VBO/IBO of quad
*/
/******************************************************************************/

Mesh* MeshBuilder::GenerateOBJ(const std::string &meshName, const std::string &file_path) 
{
	//Read vertices, texcoords & normals from OBJ
	std::vector<Position> vertices;
	std::vector<TexCoord> uvs;
	std::vector<Vector3> normals;
	bool success = LoadOBJ(file_path.c_str(), vertices, uvs, normals);

	if (!success)
	{
		return NULL;
	}
	//Index the vertices, texcoords & normals properly

	std::vector<Vertex> vertex_buffer_data;
	std::vector<GLuint> index_buffer_data;
	IndexVBO(vertices, uvs, normals, index_buffer_data, vertex_buffer_data);
	//Create the mesh and call glBindBuffer, glBufferData
	//Use triangle list and remember to set index size


	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLES;

	return mesh;
}

Mesh* MeshBuilder::GenerateText(const std::string &meshName, unsigned numRow, unsigned numCol)
{
    Vertex v;
    std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
    std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

    float width = 1.f / numCol;
    float height = 1.f / numRow;

    for (unsigned i = 0; i < numRow; ++i)
    {
        for (unsigned j = 0; j < numCol; ++j)
        {
            //Task: Add 4 vertices into vertex_buffer_data
            //v.pos.Set(0.5, 0, 0.5); v.normal.Set(0, 1, 0); v.texCoord.Set(1, 0); vertex_buffer_data.push_back(v);
            //v.pos.Set(0.5, 0, -0.5); v.normal.Set(0, 1, 0); v.texCoord.Set(1, 1); vertex_buffer_data.push_back(v);
            //v.pos.Set(-0.5, 0, 0.5); v.normal.Set(0, 1, 0); v.texCoord.Set(0, 0); vertex_buffer_data.push_back(v);
            //v.pos.Set(-0.5, 0, -0.5); v.normal.Set(0, 1, 0); v.texCoord.Set(0, 1); vertex_buffer_data.push_back(v);

            v.pos.Set(-0.5f, 0.5f, 0.f); v.normal.Set(0, 0, 1); v.texCoord.Set(j * 0.0625f, ((numRow - i - 1) + 1) * 0.0625f); vertex_buffer_data.push_back(v);
            v.pos.Set(-0.5f, -0.5f, 0.f); v.normal.Set(0, 0, 1); v.texCoord.Set(j * 0.0625f, (numRow - i - 1) * 0.0625f); vertex_buffer_data.push_back(v);
            v.pos.Set(0.5f, -0.5f, 0.f); v.normal.Set(0, 0, 1); v.texCoord.Set((j + 1) * 0.0625f, (numRow - i - 1) * 0.0625f); vertex_buffer_data.push_back(v);
            v.pos.Set(0.5f, 0.5f, 0.f); v.normal.Set(0, 0, 1); v.texCoord.Set((j + 1) * 0.0625f, ((numRow - i - 1) + 1) * 0.0625f); vertex_buffer_data.push_back(v);


            index_buffer_data.push_back((i* numCol + j) * 4 + 0);
            index_buffer_data.push_back((i* numCol + j) * 4 + 1);
            index_buffer_data.push_back((i* numCol + j) * 4 + 2);                                         
            index_buffer_data.push_back((i* numCol + j) * 4 + 0);
            index_buffer_data.push_back((i* numCol + j) * 4 + 3);
            index_buffer_data.push_back((i* numCol + j) * 4 + 2);

        }
    }

    Mesh *mesh = new Mesh(meshName);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

    mesh->indexSize = index_buffer_data.size();
    mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

    return mesh;
}

Mesh* MeshBuilder::GenerateQuad(const std::string &meshName, Color color, float lengthX, float lengthY)
{
	Vertex v;
	std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
	std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int


	//Top Face//
	v.pos.Set(0.5, 0, -0.5); v.color = color; v.normal.Set(0, 1, 0); v.texCoord.Set(1, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, 0, -0.5); v.color = color; v.normal.Set(0, 1, 0); v.texCoord.Set(0, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, 0, 0.5); v.color = color; v.normal.Set(0, 1, 0); v.texCoord.Set(0, 0); vertex_buffer_data.push_back(v);

	v.pos.Set(0.5, 0, -0.5); v.color = color; v.normal.Set(0, 1, 0); v.texCoord.Set(1, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, 0, 0.5); v.color = color; v.normal.Set(0, 1, 0); v.texCoord.Set(0, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5, 0, 0.5); v.color = color; v.normal.Set(0, 1, 0); v.texCoord.Set(1, 0); vertex_buffer_data.push_back(v);
	//End of Top Face//

	////Bottom Face//
	//v.pos.Set(-0.5, 0, -0.5); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
	//v.pos.Set(0.5, 0, 0.5); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
	//v.pos.Set(-0.5, 0, 0.5); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);

	//v.pos.Set(-0.5, 0, -0.5); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
	//v.pos.Set(0.5, 0, -0.5); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
	//v.pos.Set(0.5, 0, 0.5); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
	////End of Bottom Face//


	for (unsigned i = 0; i < 6; ++i)
	{
		index_buffer_data.push_back(i);
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLES;

	return mesh;
}

/******************************************************************************/
/*!
\brief
Generate the vertices of a cube; Use random color for each vertex
Then generate the VBO/IBO and store them in Mesh object

\param meshName - name of mesh
\param lengthX - width of cube
\param lengthY - height of cube
\param lengthZ - depth of cube

\return Pointer to mesh storing VBO/IBO of cube
*/
/******************************************************************************/

Mesh* MeshBuilder::GenerateTriangle(const std::string &meshName, Color color)
{
	//Normal Triangle
	Vertex v;
	std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
	std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

	v.pos.Set(-1, 0, -1); v.color = color; v.normal.Set(0, 1, 0); v.texCoord.Set(0, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(-1, 0, 1); v.color = color; v.normal.Set(0, 1, 0); v.texCoord.Set(0, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(1, 0, -1); v.color = color; v.normal.Set(0, 1, 0); v.texCoord.Set(1, 1); vertex_buffer_data.push_back(v);

	for (unsigned i = 0; i < 3; ++i)
	{
		index_buffer_data.push_back(i);
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLES;

	return mesh;


	//Special Triangle for Assignment 2
    //Vertex v;
    //std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
    //std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

    //v.pos.Set(1, 0, -1); v.color = color; v.normal.Set(0, 1, 0); v.texCoord.Set(1, 1); vertex_buffer_data.push_back(v);
    //v.pos.Set(-0.3, 0, -1); v.color = color; v.normal.Set(0, 1, 0); v.texCoord.Set(0.3, 1); vertex_buffer_data.push_back(v);
    //v.pos.Set(-1, 0, 1); v.color = color; v.normal.Set(0, 1, 0); v.texCoord.Set(0, 0); vertex_buffer_data.push_back(v);

    //for (unsigned i = 0; i < 3; ++i)
    //{
    //    index_buffer_data.push_back(i);
    //}

    //Mesh *mesh = new Mesh(meshName);

    //glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
    //glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);


    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

    //mesh->indexSize = index_buffer_data.size();
    //mesh->mode = Mesh::DRAW_TRIANGLES;

    //return mesh;
}

Mesh* MeshBuilder::GenerateTriPrism(const std::string &meshName, Color color, float length, float height)
{
    Vertex v;
    std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
    std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

    //Front Face//
    v.pos.Set(length, 0.f, length); v.color = color; v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);
    v.pos.Set(-length, 0.f, length); v.color = color; v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);
    v.pos.Set(0.f, height, length); v.color = color; v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);

    //End of Front Face//

    //Back Face//
    v.pos.Set(length, 0.f, -length); v.color = color; v.normal.Set(0, 0, -1); vertex_buffer_data.push_back(v);
    v.pos.Set(0.f, height, -length); v.color = color; v.normal.Set(0, 0, -1); vertex_buffer_data.push_back(v);
    v.pos.Set(-length, 0.f, -length); v.color = color; v.normal.Set(0, 0, -1); vertex_buffer_data.push_back(v);
    //End of Back Face//

    //Bottom Face//
    v.pos.Set(length, 0.f, -length); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(-length, 0.f, -length); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(-length, 0.f, length); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);

    v.pos.Set(length, 0.f, -length); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(-length, 0.f, length); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(length, 0.f, length); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
    //End of Bottom Face//

    //Left Face//
    v.pos.Set(length, 0.f, length); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(0.f, height, length); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(length, 0.f, -length); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);

    v.pos.Set(length, 0.f, -length); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(0.f, height, length); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(0.f, height, -length); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);

    //End of Left Face//

    //Right Face//
    v.pos.Set(-length, 0.f, length); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(-length, 0.f, -length); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(0.f, height, length); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);

    v.pos.Set(0.f, height, length); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(-length, 0.f, -length); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(0.f, height, -length); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
    //End of Right Face//

    for (unsigned i = 0; i < 24; ++i)
    {
        index_buffer_data.push_back(i);
    }

    Mesh *mesh = new Mesh(meshName);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

    mesh->indexSize = index_buffer_data.size();
    mesh->mode = Mesh::DRAW_TRIANGLES;

    return mesh;
}

Mesh* MeshBuilder::GeneratePyramid(const std::string &meshName, Color color, float length, float height)
{
    Vertex v;
    std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
    std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

    //Front Face//
    v.pos.Set(length, 0.f, length); v.color = color; v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);
    v.pos.Set(-0.f, height, 0.f); v.color = color; v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);
    v.pos.Set(-length, 0.f, length); v.color = color; v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);

    //End of Front Face//

    //Back Face//
    v.pos.Set(length, 0.f, -length); v.color = color; v.normal.Set(0, 0, -1); vertex_buffer_data.push_back(v);
    v.pos.Set(-length, 0.f, -length); v.color = color; v.normal.Set(0, 0, -1); vertex_buffer_data.push_back(v);
    v.pos.Set(0.f, height, 0.f); v.color = color; v.normal.Set(0, 0, -1); vertex_buffer_data.push_back(v);
    //End of Back Face//

    //Bottom Face//
    v.pos.Set(-length, 0.f, -length); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(length, 0.f, length); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(-length, 0.f, length); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);

    v.pos.Set(-length, 0.f, -length); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(length, 0.f, -length); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(length, 0.f, length); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
    //End of Bottom Face//

    //Right Face//
    v.pos.Set(length, 0.f, -length); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(0.f, height, 0.f); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(length, 0.f, length); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);

    //End of Right Face//

    //Left Face//
    v.pos.Set(-length, 0.f, length); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(0.f, height, 0.f); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
    v.pos.Set(-length, 0.f, -length); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
    //End of Left Face//

    for (unsigned i = 0; i < 18; ++i)
    {
        index_buffer_data.push_back(i);
    }

    Mesh *mesh = new Mesh(meshName);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

    mesh->indexSize = index_buffer_data.size();
    mesh->mode = Mesh::DRAW_TRIANGLES;

    return mesh;
}

Mesh* MeshBuilder::GenerateCube(const std::string &meshName, Color color)
{
	Vertex v;
	std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
	std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

		//Front Face//
	v.pos.Set(0.5, 0.5, 0.5); v.color = color; v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, 0.5, 0.5); v.color = color; v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, -0.5, 0.5); v.color = color; v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);

	v.pos.Set(0.5, 0.5, 0.5); v.color = color; v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, -0.5, 0.5); v.color = color; v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5, -0.5, 0.5); v.color = color; v.normal.Set(0, 0, 1); vertex_buffer_data.push_back(v);
		//End of Front Face//

		//Back Face//
	v.pos.Set(0.5, 0.5, -0.5); v.color = color; v.normal.Set(0, 0, -1); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5, -0.5, -0.5); v.color = color; v.normal.Set(0, 0, -1); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, 0.5, -0.5); v.color = color; v.normal.Set(0, 0, -1); vertex_buffer_data.push_back(v);

	v.pos.Set(-0.5, 0.5, -0.5); v.color = color; v.normal.Set(0, 0, -1); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5, -0.5, -0.5); v.color = color; v.normal.Set(0, 0, -1); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, -0.5, -0.5); v.color = color; v.normal.Set(0, 0, -1); vertex_buffer_data.push_back(v);
		//End of Back Face//


		//Top Face//
	v.pos.Set(0.5, 0.5, -0.5); v.color = color; v.normal.Set(0, 1, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, 0.5, -0.5); v.color = color; v.normal.Set(0, 1, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, 0.5, 0.5); v.color = color; v.normal.Set(0, 1, 0); vertex_buffer_data.push_back(v);

	v.pos.Set(0.5, 0.5, -0.5); v.color = color; v.normal.Set(0, 1, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, 0.5, 0.5); v.color = color; v.normal.Set(0, 1, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5, 0.5, 0.5); v.color = color; v.normal.Set(0, 1, 0); vertex_buffer_data.push_back(v);
		//End of Top Face//

		//Bottom Face//
	v.pos.Set(-0.5, -0.5, -0.5); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5, -0.5, 0.5); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, -0.5, 0.5); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);

	v.pos.Set(-0.5, -0.5, -0.5); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5, -0.5, -0.5); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5, -0.5, 0.5); v.color = color; v.normal.Set(0, -1, 0); vertex_buffer_data.push_back(v);
		//End of Bottom Face//

		//Right Face//
	v.pos.Set(0.5, 0.5, -0.5); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5, 0.5, 0.5); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5, -0.5, 0.5); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);

	v.pos.Set(0.5, 0.5, -0.5); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5, -0.5, 0.5); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(0.5, -0.5, -0.5); v.color = color; v.normal.Set(1, 0, 0); vertex_buffer_data.push_back(v);
		//End of Right Face//

		//Left Face//
	v.pos.Set(-0.5, 0.5, 0.5); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, 0.5, -0.5); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, -0.5, -0.5); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);

	v.pos.Set(-0.5, 0.5, 0.5); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, -0.5, -0.5); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
	v.pos.Set(-0.5, -0.5, 0.5); v.color = color; v.normal.Set(-1, 0, 0); vertex_buffer_data.push_back(v);
		//End of Left Face//

	for (unsigned i = 0; i < 36; ++i)
	{
		index_buffer_data.push_back(i);
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLES;

	return mesh;
}

Mesh* MeshBuilder::GenerateCircle(const std::string &meshName, Color color, unsigned numSlices, float radius)
{
    Vertex v;
    std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
    std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

    float anglePerSlice = 360.f / numSlices;

    for (unsigned slice = 0; slice < numSlices + 1; ++slice)
    {
        float theta = slice * anglePerSlice;
        v.pos.Set(radius * cos(Math::DegreeToRadian(theta)), 0, radius * sin(Math::DegreeToRadian(theta)));
        v.color = color;

        v.normal.Set(cos(Math::DegreeToRadian(theta)),
            0,
            sin(Math::DegreeToRadian(theta)));

        vertex_buffer_data.push_back(v);
    }

	v.pos.Set(0, 0, 0);
	//Cone
	//v.pos.Set(0, 1, 0);
	v.color = color;
	vertex_buffer_data.push_back(v);


    for (unsigned i = 0; i < 2* (numSlices + 1); ++i)
    {
        index_buffer_data.push_back(i);
		index_buffer_data.push_back(numSlices + 1);
    }

    Mesh *mesh = new Mesh(meshName);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

    mesh->indexSize = index_buffer_data.size();
    mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

    return mesh;
}

Mesh* MeshBuilder::GenerateCone(const std::string &meshName, Color color, unsigned numSlices, float radius, float height)
{
    Vertex v;
    std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
    std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

    float anglePerSlice = 360.f / numSlices;


    for (unsigned slice = 0; slice < numSlices + 1; ++slice) //slice
    {
        float theta = slice * anglePerSlice;
        v.pos.Set(radius * cos(Math::DegreeToRadian(theta)), -height *0.5f, radius * sin(Math::DegreeToRadian(theta)));
        vertex_buffer_data.push_back(v);

        v.pos.Set(0.f, height * 0.5f, 0.f);
        vertex_buffer_data.push_back(v);
    }

    for (unsigned slice = 0; slice < numSlices + 1; ++slice) //bottom
    {
        float theta = slice * anglePerSlice;
        v.pos.Set(0.f, -height * 0.5f, 0.f);
        vertex_buffer_data.push_back(v);
        v.pos.Set(radius * cos(Math::DegreeToRadian(theta)), -height * 0.5f, radius * sin(Math::DegreeToRadian(theta)));
        vertex_buffer_data.push_back(v);
    }

    for (unsigned i = 0; i < 2 * ((numSlices + 1) * 2); ++i)
    {
        //index_buffer_data.push_back(numSlices + 1);
        index_buffer_data.push_back(i);
    }


    Mesh *mesh = new Mesh(meshName);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

    mesh->indexSize = index_buffer_data.size();
    mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

    return mesh;
}

Mesh * MeshBuilder::GenerateSemiCircle(const std::string &meshName, Color color, unsigned numSlices, unsigned outerRadius, unsigned innerRadius)
{
    Vertex v;
    std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
    std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

    float anglePerSlice = 180.f / numSlices;

    for (unsigned slice = 0; slice <= numSlices; ++slice)
    {
        float theta = slice * anglePerSlice;
        v.pos.Set(outerRadius * cos(Math::DegreeToRadian(theta)), 0, outerRadius * sin(Math::DegreeToRadian(theta)));
        v.color = color;
        v.normal.Set(cos(Math::DegreeToRadian(theta)), 0, sin(Math::DegreeToRadian(theta)));
        vertex_buffer_data.push_back(v);

        v.pos.Set(innerRadius * cos(Math::DegreeToRadian(theta)), 0, innerRadius * sin(Math::DegreeToRadian(theta)));
        v.normal.Set(cos(Math::DegreeToRadian(theta)), 0, sin(Math::DegreeToRadian(theta)));
        vertex_buffer_data.push_back(v);
    }

    for (unsigned i = 0; i < (numSlices + 1) * 4; ++i)
    {
        index_buffer_data.push_back(i);
    }

    Mesh *mesh = new Mesh(meshName);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

    mesh->indexSize = index_buffer_data.size();
    mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

    return mesh;
}

Mesh * MeshBuilder::GenerateRing(const std::string &meshName, Color color, unsigned numSlices, unsigned outerRadius, unsigned innerRadius)
{
    Vertex v;
    std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
    std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

    float anglePerSlice = 360.f / numSlices;

    for (unsigned slice = 0; slice <= numSlices; ++slice)
    {
        float theta = slice * anglePerSlice;
        v.pos.Set(outerRadius * cos(Math::DegreeToRadian(theta)), 0, outerRadius * sin(Math::DegreeToRadian(theta)));
        v.color = color;
        vertex_buffer_data.push_back(v);

        v.pos.Set(innerRadius * cos(Math::DegreeToRadian(theta)), 0, innerRadius * sin(Math::DegreeToRadian(theta)));
        vertex_buffer_data.push_back(v);
    }

    anglePerSlice = -360.f / numSlices;

    for (unsigned slice = 0; slice <= numSlices; ++slice)
    {
        float theta = slice * anglePerSlice;
        v.pos.Set(outerRadius * cos(Math::DegreeToRadian(theta)), 0, outerRadius * sin(Math::DegreeToRadian(theta)));
        v.color = color;
        vertex_buffer_data.push_back(v);

        v.pos.Set(innerRadius * cos(Math::DegreeToRadian(theta)), 0, innerRadius * sin(Math::DegreeToRadian(theta)));
        vertex_buffer_data.push_back(v);
    }

    for (unsigned i = 0; i < ((numSlices + 1) * 2) * 2; ++i)
    {
        index_buffer_data.push_back(i);
    }

    Mesh *mesh = new Mesh(meshName);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

    mesh->indexSize = index_buffer_data.size();
    mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

    return mesh;
}

Mesh * MeshBuilder::GenerateSphere(const std::string &meshName, Color color, unsigned numSlices, unsigned numStacks, float radius)
{
	Vertex v;
	std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
	std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

		float anglePerSlice = 360.0f / numSlices;
		float anglePerStack = 180.0f / numStacks;

	for (float stack = 0.f; stack < numStacks + 1; ++stack) //stack //replace with 180 for sphere
	{
		float phi = -90.f + stack * anglePerStack;

		for (float slice = 0.f; slice < numSlices + 1; ++slice) //slice
		{
			float theta = slice * anglePerSlice;
			v.pos.Set((radius * cos(Math::DegreeToRadian(phi)) * cos(Math::DegreeToRadian(theta))),
				(radius * sin(Math::DegreeToRadian(phi))),
				(radius * cos(Math::DegreeToRadian(phi)) *sin(Math::DegreeToRadian(theta))));

			v.color = color;

			v.normal.Set((cos(Math::DegreeToRadian(phi)) * cos(Math::DegreeToRadian(theta))),
				(sin(Math::DegreeToRadian(phi))),
				(cos(Math::DegreeToRadian(phi)) *sin(Math::DegreeToRadian(theta))));

			vertex_buffer_data.push_back(v);

		}
	}


	for (float stack = 0.f; stack <= numStacks; ++stack) //stack //replace with 180 for sphere
	{
		for (float slice = 0.f; slice <= numSlices + 1; ++slice) //stack //replace with 180 for sphere
		{
			index_buffer_data.push_back(stack * (numSlices + 1) + slice);
			index_buffer_data.push_back((stack + 1) * (numSlices + 1) + slice);
		}
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;
}


Mesh * MeshBuilder::GenerateHemisphere(const std::string &meshName, Color color, unsigned numSlices, unsigned numStacks, float radius)
{
    Vertex v;
    std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
    std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

    float anglePerSlice = 360.0f / numSlices;
    float anglePerStack = 180.0f / numStacks;

    for (float stack = 0.f; stack < numStacks + 1; ++stack) //stack //replace with 180 for sphere
    {
        float phi = 0.f + stack * anglePerStack;

        for (float slice = 0.f; slice < numSlices + 1; ++slice) //slice
        {
            float theta = slice * anglePerSlice;
            v.pos.Set((radius * cos(Math::DegreeToRadian(phi)) * cos(Math::DegreeToRadian(theta))),
                (radius * sin(Math::DegreeToRadian(phi))),
                (radius * cos(Math::DegreeToRadian(phi)) *sin(Math::DegreeToRadian(theta))));

            v.color = color;

            v.normal.Set((cos(Math::DegreeToRadian(phi)) * cos(Math::DegreeToRadian(theta))),
                (sin(Math::DegreeToRadian(phi))),
                (cos(Math::DegreeToRadian(phi)) *sin(Math::DegreeToRadian(theta))));

            vertex_buffer_data.push_back(v);

        }
    }


    for (float stack = 0.f; stack <= numStacks; ++stack) //stack //replace with 180 for sphere
    {
        for (float slice = 0.f; slice <= numSlices + 1; ++slice) //stack //replace with 180 for sphere
        {
            index_buffer_data.push_back(stack * (numSlices + 1) + slice);
            index_buffer_data.push_back((stack + 1) * (numSlices + 1) + slice);
        }
    }

    Mesh *mesh = new Mesh(meshName);

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

    mesh->indexSize = index_buffer_data.size();
    mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

    return mesh;
}


Mesh*::MeshBuilder::GenerateCylinder(const std::string &meshName, Color color, unsigned numSlices, float radius, float height)
{
	Vertex v;
	std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
	std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

	float anglePerSlice = 360.f / numSlices;


	//Bottom
	for (unsigned slice = 0; slice < numSlices + 1; ++slice)
	{
		float theta = slice * anglePerSlice;
		v.pos.Set(radius * cos(Math::DegreeToRadian(theta)), -height * 0.5f, radius * sin(Math::DegreeToRadian(theta)));
		v.color = color;
		vertex_buffer_data.push_back(v);
	}

	v.pos.Set(0, -height * 0.5f, 0);
	v.color = color;
	vertex_buffer_data.push_back(v);

	//Curve Side
	for (unsigned slice = 0; slice < numSlices + 1; ++slice)
	{
		float theta = slice * anglePerSlice;
		v.pos.Set(radius * cos(Math::DegreeToRadian(theta)), height * 0.5f, radius * sin(Math::DegreeToRadian(theta)));
		v.color = color;
		vertex_buffer_data.push_back(v);

		v.pos.Set(radius * cos(Math::DegreeToRadian(theta)), -height * 0.5f, radius * sin(Math::DegreeToRadian(theta)));
		v.color = color;
		vertex_buffer_data.push_back(v);
	}

	//Top
	for (unsigned slice = 0; slice < numSlices + 1; ++slice)
	{
		float theta = slice * anglePerSlice;
		v.pos.Set(radius * cos(Math::DegreeToRadian(theta)), height * 0.5f, radius * sin(Math::DegreeToRadian(theta)));
		v.color = color;
		vertex_buffer_data.push_back(v);
	}

	v.pos.Set(0, height * 0.5f, 0);
	v.color = color;
	vertex_buffer_data.push_back(v);


	for (unsigned i = 0; i < numSlices + 1; ++i)
	{
		index_buffer_data.push_back(numSlices + 1);
		index_buffer_data.push_back(i);
	}

	for (unsigned i = 0; i < numSlices + 1; ++i)
	{
		index_buffer_data.push_back(numSlices + 2 + i * 2 + 1);
		index_buffer_data.push_back(numSlices + 2 + i * 2);
	}

	for (unsigned i = 0; i < numSlices + 1; ++i)
	{
		index_buffer_data.push_back(numSlices + 2 + (numSlices + 1) * 2 + i);
		index_buffer_data.push_back(numSlices + 2 + (numSlices + 1) * 2 + numSlices + 1);
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;
}

//Mesh*::MeshBuilder::GenerateTorus2(const std::string &meshName, unsigned numStack, unsigned numSlice, float outerR, float innerR)
//{
	//Vertex v;
	//std::vector<Vertex>vertex_buffer_data; //Vertex Buffer Data
	//std::vector<unsigned>index_buffer_data;; //unsigned == unsigned int

	//float degreePerStack = 360.f / numStack;
	//float degreePerSlice = 360.f / numSlice;
	//float x1, z1; //y1 is always zero
	//float x2, y2, z2;

	//for (unsigned stack = 0; stack < numStack + 1; stack++) {
	//	for (unsigned slice = 0; slice < numSlice + 1; slice++) {
	//		z1 = outerR * cos(stack * degreePerStack);
	//		x1 = outerR * sin(stack * degreePerStack);
	//		z2 = (outerR + innerR * cos(slice * degreePerSlice)) * cos(stack * degreePerStack);
	//		y2 = innerR * sin(slice * degreePerSlice);
	//		x2 = (outerR + innerR * cos(slice * degreePerSlice)) * sin(stack * degreePerStack);
	//		v.pos.Set(x2, y2, z2);
	//		v.normal.Set(x2 - x1, y2, z2 - z1);
	//	}
	//}

	//for (unsigned stack = 0; stack < numStack; stack++) {
	//	for (unsigned slice = 0; slice < numSlice + 1; slice++) {
	//		index_buffer_data.push_back((numSlice + 1) * stack + slice + 0);
	//		index_buffer_data.push_back((numSlice + 1) * (stack + 1) + slice + 0);
	//	}
	//}

	////Add normals for lighting
	//for (theta = 0; theta <= 360; theta += 10) //slice
	//	v.normal.Set(HEIGHT * x(theta), RADIUS, HEIGHT * z(theta)))
	//	add_vertex(RADIUS * x(theta), -HEIGHT / 2, RADIUS * z(theta))
	//	add_normal(normalize(HEIGHT * x(theta), RADIUS, HEIGHT * z(theta))) //z not y hieght * cos(theta), Radius H
	//	add_vertex(0, HEIGHT / 2, 0)
	//	for (theta = 0; theta <= 360; theta += 10) //bottom
	//		add_normal(0, -1, 0)
	//		add_vertex(0, -HEIGHT / 2, 0)
	//		add_normal(0, -1, 0)
	//		add_vertex(x(theta), -HEIGHT / 2, z(theta))



			//for (unsigned stack = 0; stack < numStack + 1; stack++)
			//{
			//	for (unsigned slice = 0; slice < numSlice + 1; slice++) 
			//	{
			//		z1 = outerR * cos(stack * degreePerStack);
			//		x1 = outerR * sin(stack * degreePerStack);
			//		z2 = (outerR + innerR * cos(slice * degreePerSlice)) * cos(stack * degreePerStack);
			//		y2 = innerR * sin(slice * degreePerSlice);
			//		x2 = (outerR + innerR * cos(slice * degreePerSlice)) * sin(stack * degreePerStack);
			//		v.pos.Set(x2, y2, z2);
			//		v.normal.Set(x2 - x1, y2, z2 - z1);
			//	}
			//}

			//for (unsigned stack = 0; stack < numStack; stack++) 
			//{
			//	for (unsigned slice = 0; slice < numSlice + 1; slice++) 
			//	{
			//		index_buffer_data.push_back((numSlice + 1) * stack + slice + 0);
			//		index_buffer_data.push_back((numSlice + 1) * (stack + 1) + slice + 0);
			//	}
			//}

	//		v.normal.Set(height * cost(Math::DegreeToRadian(theta)), radius, height * sin(Math::DegreeToRadian(theta)));
	//v.pos.Set(0, height, 0);
	//v.color = color;

	//Mesh *mesh = new Mesh(meshName);

	//glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	//glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer_data.size() * sizeof(unsigned), &index_buffer_data[0], GL_STATIC_DRAW);

	//mesh->indexSize = index_buffer_data.size();
	//mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	//return mesh;
//}

