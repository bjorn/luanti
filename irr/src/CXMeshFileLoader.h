// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#pragma once

#include "IMeshLoader.h"
#include "ISceneManager.h"
#include "IReadFile.h"

namespace scene
{

//! Meshloader capable of loading .x meshes.
//! See https://paulbourke.net/dataformats/directx/ for a specification.
class CXMeshFileLoader : public IMeshLoader
{
public:
	//! Constructor
	CXMeshFileLoader(scene::ISceneManager *smgr);

	//! returns true if the file maybe is able to be loaded by this class
	//! based on the file extension (e.g. ".cob")
	bool isALoadableFileExtension(const io::path &filename) const override;

	//! creates/loads an animated mesh from the file.
	//! \return Pointer to the created mesh. Returns 0 if loading failed.
	//! If you no longer need the mesh, you should call IAnimatedMesh::drop().
	//! See IReferenceCounted::drop() for more information.
	IAnimatedMesh *createMesh(io::IReadFile *file) override;
};

} // end namespace scene
