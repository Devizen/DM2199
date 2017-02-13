#include "Material.h"

Material::Material()
{
	kAmbient.Set(0.2f, 0.2f, 0.2f);
	kDiffuse.Set(0.6f, 0.6f, 0.6f);
	kSpecular.Set(0.3f, 0.3f, 0.3f); //How much light to reflect
	kShininess = 1; //How shiny
}

Material::~Material()
{

}