// pour Windows
#ifdef _WIN32
#include <Windows.h>
#endif

#include <iostream>
#include <vector>

// Math
#include <cmath>
#include <cfloat>
#include <osg/Export>

using namespace std;

// base
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>

// Keyboard input
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>

// Material
#include<osg/Material>

//StateSet
#include<osg/StateSet>

//Position
#include<osg/PositionAttitudeTransform>

//Matrice et Géometrie
#include <osg/MatrixTransform>
#include <osg/Geometry>

//Lecture fichier
#include <osgDB/ReadFile>

//Textures
#include <osgDB/readFile>
#include <osg/Texture2D>

//Lumières 
#include <osg/Light>
#include <osg/LightSource>

//Brouillard 
#include <osg/Fog>


int main()
{
	/* OBJECTS CREATION */

	//Creating the viewer	
	osgViewer::Viewer viewer;

	//Creating the root node
	osg::ref_ptr<osg::Group> root(new osg::Group);

	//The geode containing our shape
	osg::ref_ptr<osg::Geode> myshapegeode(new osg::Geode);
	//Our shape: a Line (Box)
	osg::ref_ptr<osg::Box> myBox(new osg::Box(osg::Vec3f(0, 0, 0), 13.25, 0.25, 0.25));
	//ShapeDrawable
	osg::ref_ptr<osg::ShapeDrawable> boxdrawable(new osg::ShapeDrawable(myBox.get()));

	/* Positionnement */

	//Create the transformation node
	// arretes x
	osg::ref_ptr<osg::PositionAttitudeTransform> objectPat1(new osg::PositionAttitudeTransform);
	osg::Vec3f objectPosTrans(0, 0, 0);
	objectPat1->setPosition(objectPosTrans);

	osg::ref_ptr<osg::PositionAttitudeTransform> objectPat2(new osg::PositionAttitudeTransform);
	osg::Vec3f objectPosTrans2(0, 0, -13);
	objectPat2->setPosition(objectPosTrans2);

	osg::ref_ptr<osg::PositionAttitudeTransform> objectPat3(new osg::PositionAttitudeTransform);
	osg::Vec3f objectPosTrans3(0, 13, 0);
	objectPat3->setPosition(objectPosTrans3);

	osg::ref_ptr<osg::PositionAttitudeTransform> objectPat4(new osg::PositionAttitudeTransform);
	osg::Vec3f objectPosTrans4(0, 13, -13);
	objectPat4->setPosition(objectPosTrans4);
	// arretes y
	osg::ref_ptr<osg::PositionAttitudeTransform> objectPat5(new osg::PositionAttitudeTransform);
	osg::Vec3f objectPosTrans5(6.5, 0, 6.5);
	objectPat5->setPosition(objectPosTrans5);

	osg::ref_ptr<osg::PositionAttitudeTransform> objectPat6(new osg::PositionAttitudeTransform);
	osg::Vec3f objectPosTrans6(6.5, 0, -6.5);
	objectPat6->setPosition(objectPosTrans6);

	osg::ref_ptr<osg::PositionAttitudeTransform> objectPat7(new osg::PositionAttitudeTransform);
	osg::Vec3f objectPosTrans7(6.5, 13, 6.5);
	objectPat7->setPosition(objectPosTrans7);

	osg::ref_ptr<osg::PositionAttitudeTransform> objectPat8(new osg::PositionAttitudeTransform);
	osg::Vec3f objectPosTrans8(6.5, 13, -6.5);
	objectPat8->setPosition(objectPosTrans8);
	// arretes z
	osg::ref_ptr<osg::PositionAttitudeTransform> objectPat9(new osg::PositionAttitudeTransform);
	osg::Vec3f objectPosTrans9(6.5, 6.5, 0);
	objectPat9->setPosition(objectPosTrans9);

	osg::ref_ptr<osg::PositionAttitudeTransform> objectPat10(new osg::PositionAttitudeTransform);
	osg::Vec3f objectPosTrans10(6.5, -6.5, 0);
	objectPat10->setPosition(objectPosTrans10);

	osg::ref_ptr<osg::PositionAttitudeTransform> objectPat11(new osg::PositionAttitudeTransform);
	osg::Vec3f objectPosTrans11(6.5, 6.5, -13);
	objectPat11->setPosition(objectPosTrans11);

	osg::ref_ptr<osg::PositionAttitudeTransform> objectPat12(new osg::PositionAttitudeTransform);
	osg::Vec3f objectPosTrans12(6.5, -6.5, -13);
	objectPat12->setPosition(objectPosTrans12);

	//Matrix transform (rotation des arretes)
	// arretes selon y
	osg::MatrixTransform* RotationY = new osg::MatrixTransform;
	const double angle = osg::PI_2;
	const osg::Vec3d axisY(0, 1, 0);
	RotationY->setMatrix(osg::Matrix::rotate(angle, axisY));
	RotationY->addChild(objectPat5);
	RotationY->addChild(objectPat6);
	RotationY->addChild(objectPat7);
	RotationY->addChild(objectPat8);
	// arretes selon z
	osg::MatrixTransform* RotationZ = new osg::MatrixTransform;
	const osg::Vec3d axisZ(0, 0, 1);
	RotationZ->setMatrix(osg::Matrix::rotate(angle, axisZ));
	RotationZ->addChild(objectPat9);
	RotationZ->addChild(objectPat10);
	RotationZ->addChild(objectPat11);
	RotationZ->addChild(objectPat12);

	//Add the object to tranform
	objectPat1->addChild(myshapegeode);
	objectPat2->addChild(myshapegeode);
	objectPat3->addChild(myshapegeode);
	objectPat4->addChild(myshapegeode);
	objectPat5->addChild(myshapegeode);
	objectPat6->addChild(myshapegeode);
	objectPat7->addChild(myshapegeode);
	objectPat8->addChild(myshapegeode);
	objectPat9->addChild(myshapegeode);
	objectPat10->addChild(myshapegeode);
	objectPat11->addChild(myshapegeode);
	objectPat12->addChild(myshapegeode);

	vector<osg::ref_ptr<osg::PositionAttitudeTransform>> VectPAT[12];



	/* SCENE GRAPH*/

		// Add the shape drawable to the geode
	myshapegeode->addDrawable(boxdrawable.get());

	// Add the geode to the scene graph root (Group)
	root->addChild(objectPat1.get());
	root->addChild(objectPat2.get());
	root->addChild(objectPat3.get());
	root->addChild(objectPat4.get());
	root->addChild(RotationY);
	root->addChild(RotationZ);




	// Set the scene data
	viewer.setSceneData(root.get());

	/* KEYBOARD INPUT */

		//Stats Event Handler s key
	viewer.addEventHandler(new osgViewer::StatsHandler);

	//Windows size handler
	viewer.addEventHandler(new osgViewer::WindowSizeHandler);

	// add the state manipulator
	viewer.addEventHandler(new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()));



	/* START VIEWER */

		//The viewer.run() method starts the threads and the traversals.
	return (viewer.run());

}
