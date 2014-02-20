#pragma once

// A DrawableElement is a unique
// element containing an id and just
// enough information for a View to render
// it onscreen.

#include "Entity.h"
#include "vec.h"

#include <vector>

// TODO: add render data, duh

class DrawableElement
{
public:
	DrawableElement(id_t id); // standard ctor generates an element that is invisible upon rendering
	DrawableElement(id_t id, const std::vector<vec3d> & data);
	~DrawableElement();

	// Checks to see if both drawable elements refer to the same
	// entity, by matching ID.
	bool hasCommonEntity(const DrawableElement * other) const;

	id_t getEntityId() const;

	std::vector<vec3d> getData() const;

	bool operator<(const DrawableElement & rhs) const;
	bool operator==(const DrawableElement & rhs) const;

private:
	std::vector<vec3d> vertexes;

	id_t associated_entity_id;
};

bool cmp_drawable_elt_ptr_lt(const DrawableElement * lhs, const DrawableElement * rhs);

class cmp_de_ptr_lt_ftor{
public:
	bool operator()(const DrawableElement * lhs, const DrawableElement * rhs){
		return cmp_drawable_elt_ptr_lt(lhs, rhs);
	}
};