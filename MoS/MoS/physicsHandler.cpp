#include "physicsHandler.h"
#include "Sphere.h"
#include "Box.h"
#include <iostream>



physicsHandler::physicsHandler()
{
}


physicsHandler::~physicsHandler()
{
}

void physicsHandler::calculateTime()
{
	float newTime = glfwGetTime();
	deltaTime = newTime - currTime;
	currTime = newTime;
}

void physicsHandler::integrate()
{
	//glm::vec3 newVel = currVel + deltaTime*currAcc;
	//glm::vec3 newPos = currPos + deltaTime*newVel;
}

void physicsHandler::calculatePosition(vector<Entity*> *theEntityList, GLFWwindow *window)
{

	for (int i = 0; i < theEntityList->size(); i++)
	{
		glm::vec3 currPos = theEntityList->at(i)->getPosition();
		glm::vec3 currAcc = theEntityList->at(i)->getAcceleration();
		glm::vec3 currVel = theEntityList->at(i)->getVelocity();
<<<<<<< HEAD
		glm::vec3 gravity = glm::vec3(0.0f, -9.81f, 0.0f)*2.0f;

		//INPUT CHECK

		if (glfwGetKey(window, GLFW_KEY_LEFT)) {

			currAcc = (gravity + glm::vec3(-40.0f, 0.0f, 0.0f));
			cout << currVel.x << " " << currVel.y << " " << currVel.z << endl;
=======
		glm::vec3 gravity = glm::vec3(0.0f, -9.81f, 0.0f)*0.1f;

		//INPUT CHECK

		if (glfwGetKey(window, GLFW_KEY_KP_4)) {

			currAcc = (gravity + glm::vec3(-40.0f, 0.0f, 0.0f));
>>>>>>> experimental
		}
		else
		{
			currAcc = gravity;
		}

<<<<<<< HEAD
		if (glfwGetKey(window, GLFW_KEY_W)) {

			currAcc = (gravity + glm::vec3(0.0f, 100.0f, 0.0f));
			cout << currVel.x << " " << currVel.y << " " << currVel.z << endl;

		}

		if (glfwGetKey(window, GLFW_KEY_RIGHT)) {

			currAcc = (gravity + glm::vec3(40.0f, 0.0f, 0.0f));
			cout << currVel.x << " " << currVel.y << " " << currVel.z << endl;
		}

		if (glfwGetKey(window, GLFW_KEY_S)) {

			currAcc = (gravity + glm::vec3(0.0f, -100.0f, 0.0f));
			cout << currVel.x << " " << currVel.y << " " << currVel.z << endl;
		}
		if (glfwGetKey(window, GLFW_KEY_UP)) {

			currAcc = (gravity + glm::vec3(0.0f, 0.0f, -40.0f));
			cout << currVel.x << " " << currVel.y << " " << currVel.z << endl;
		}
		if (glfwGetKey(window, GLFW_KEY_DOWN)) {

			currAcc = (gravity + glm::vec3(0.0f, 0.0f, 40.0f));
			cout << currVel.x << " " << currVel.y << " " << currVel.z << endl;
=======
		if (glfwGetKey(window, GLFW_KEY_KP_9)) {

			currAcc = (gravity + glm::vec3(0.0f, 100.0f, 0.0f));

		}

		if (glfwGetKey(window, GLFW_KEY_KP_6)) {

			currAcc = (gravity + glm::vec3(40.0f, 0.0f, 0.0f));
		}

		if (glfwGetKey(window, GLFW_KEY_KP_7)) {

			currAcc = (gravity + glm::vec3(0.0f, -100.0f, 0.0f));
		}
		if (glfwGetKey(window, GLFW_KEY_KP_8)) {

			currAcc = (gravity + glm::vec3(0.0f, 0.0f, -40.0f));
		}
		if (glfwGetKey(window, GLFW_KEY_KP_2)) {

			currAcc = (gravity + glm::vec3(0.0f, 0.0f, 40.0f));

>>>>>>> experimental
		}


		//EULER CALC 
		glm::vec3 newVel = currVel + deltaTime*currAcc;
		glm::vec3 newPos = currPos + deltaTime*newVel;

		theEntityList->at(i)->setAcceleration(currAcc);
		theEntityList->at(i)->setVelocity(newVel);
		theEntityList->at(i)->setPosition(newPos);
	}

}

void physicsHandler::resolveCollision(vector<Entity*> * theEntityList)
{
	glm::vec3 iVel;
	glm::vec3 iPos;
	glm::vec3 jPos;
<<<<<<< HEAD
	glm::vec3 posVector;
	float vLength;
=======
	glm::vec3 jVel;

	glm::vec3 posVector;
	float vLength;
	float diffVel;
>>>>>>> experimental

	glm::vec3 normal;
	glm::vec3 p1Normal;
	glm::vec3 p2Normal;
	glm::mat4 coSystem;

<<<<<<< HEAD
	glm::vec4 reflectedNewVel;
	glm::vec4 nreflectedNewVel;

	float rad1 = 0.5f;
	float rad2 = 0.5f;
	for (int i = 0; i < theEntityList->size(); i++)
=======
	glm::vec4 reflectedNewVel_1;
	glm::vec4 nreflectedNewVel_1;

	glm::vec4 reflectedNewVel_2;
	glm::vec4 nreflectedNewVel_2;

	glm::vec4 nBasePos;

	float rad1 = 0.5f;
	float rad2 = 0.5f;
	for (int i = 0; i < theEntityList->size() - 1; i++)
>>>>>>> experimental
	{
		iPos = theEntityList->at(i)->getPosition();
		iVel = theEntityList->at(i)->getVelocity();

<<<<<<< HEAD
		for (int j = 0; j < theEntityList->size(); j++)
		{
			 
			jPos = theEntityList->at(j)->getPosition();
=======
		for (int j = i + 1; j < theEntityList->size(); j++)
		{
			 
			jPos = theEntityList->at(j)->getPosition();
			jVel = theEntityList->at(j)->getVelocity();
>>>>>>> experimental

			posVector = iPos - jPos;
			vLength = glm::length(posVector);

			if (vLength < rad1 + rad2 && i != j)
			{
<<<<<<< HEAD
=======
				float move = (rad1 + rad2 - vLength);

				move = move / 2.0f;

>>>>>>> experimental
				normal = posVector;
				p1Normal = glm::cross(normal, glm::cross(normal, glm::vec3(normal.z, -normal.x, -normal.y)));
				p2Normal = glm::cross(normal, p1Normal);
				coSystem = glm::mat4(glm::vec4(normal, 0.0f), glm::vec4(p1Normal, 0.0f), glm::vec4(p2Normal, 0.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

<<<<<<< HEAD
				reflectedNewVel = glm::vec4(glm::reflect(iVel, normal), 1.0f);
				nreflectedNewVel = glm::inverse(coSystem)*reflectedNewVel;

				nreflectedNewVel = glm::vec4(nreflectedNewVel.x*0.5f, nreflectedNewVel.y, nreflectedNewVel.z, 1.0f);

				reflectedNewVel = coSystem*nreflectedNewVel;

				theEntityList->at(i)->setVelocity(glm::vec3(reflectedNewVel));
=======
				
				reflectedNewVel_1 = glm::vec4(glm::reflect(iVel, normal), 1.0f);
				nreflectedNewVel_1 = glm::inverse(coSystem)*reflectedNewVel_1;
				
				reflectedNewVel_2 = glm::vec4(glm::reflect(jVel, -normal), 1.0f);
				nreflectedNewVel_2 = glm::inverse(coSystem)*reflectedNewVel_2;
				
				diffVel = nreflectedNewVel_1.x - nreflectedNewVel_2.x;

				nreflectedNewVel_1 = glm::vec4((nreflectedNewVel_1.x+diffVel)*0.6f, nreflectedNewVel_1.y, nreflectedNewVel_1.z, 1.0f);
				reflectedNewVel_1 = coSystem*nreflectedNewVel_1;
				theEntityList->at(i)->setVelocity(glm::vec3(reflectedNewVel_1));

				nreflectedNewVel_2 = glm::vec4((nreflectedNewVel_2.x-diffVel)*0.5f, nreflectedNewVel_2.y, nreflectedNewVel_2.z, 1.0f);
				reflectedNewVel_2 = coSystem*nreflectedNewVel_2;
				theEntityList->at(j)->setVelocity(glm::vec3(reflectedNewVel_2));

				//FIRST BALL
				nBasePos = glm::inverse(coSystem)*glm::vec4(iPos, 1.0f);
				nBasePos = glm::vec4(nBasePos.x + move, nBasePos.y, nBasePos.z, 1.0f);
				nBasePos = coSystem*nBasePos;
				theEntityList->at(i)->setPosition(glm::vec3(nBasePos));

				//SECOND BALL
				nBasePos = glm::inverse(coSystem)*glm::vec4(jPos, 1.0f);
				nBasePos = glm::vec4(nBasePos.x - move, nBasePos.y, nBasePos.z, 1.0f);
				nBasePos = coSystem*nBasePos;
				theEntityList->at(j)->setPosition(glm::vec3(nBasePos));

>>>>>>> experimental
				//theEntityList->at(i)->setPosition(glm::vec3(currPos.x, 0.50001f, currPos.z));
			}

		}

		glm::vec3 currPos = theEntityList->at(i)->getPosition();
		glm::vec3 currVel = theEntityList->at(i)->getVelocity();
		//COLLISION DETECT move to separate function later	
		if (currPos.y < 0.5)
		{
			normal = glm::vec3(0.1f, 1.0f, 0.0f);
			p1Normal = glm::cross(normal, glm::cross(normal, glm::vec3(normal.z, -normal.x, -normal.y)));
			p2Normal = glm::cross(normal, p1Normal);
			coSystem = glm::mat4(glm::vec4(normal, 0.0f), glm::vec4(p1Normal, 0.0f), glm::vec4(p2Normal, 0.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

<<<<<<< HEAD
			reflectedNewVel = glm::vec4(glm::reflect(currVel, normal), 1.0f);
			nreflectedNewVel = glm::inverse(coSystem)*reflectedNewVel;

			nreflectedNewVel = glm::vec4(nreflectedNewVel.x*0.5f, nreflectedNewVel.y, nreflectedNewVel.z, 1.0f);

			reflectedNewVel = coSystem*nreflectedNewVel;

			theEntityList->at(i)->setVelocity(glm::vec3(reflectedNewVel));
=======
			reflectedNewVel_1 = glm::vec4(glm::reflect(currVel, normal), 1.0f);
			nreflectedNewVel_1 = glm::inverse(coSystem)*reflectedNewVel_1;

			nreflectedNewVel_1 = glm::vec4(nreflectedNewVel_1.x*0.5f, nreflectedNewVel_1.y, nreflectedNewVel_1.z, 1.0f);

			reflectedNewVel_1 = coSystem*nreflectedNewVel_1;

			theEntityList->at(i)->setVelocity(glm::vec3(reflectedNewVel_1));
>>>>>>> experimental
			theEntityList->at(i)->setPosition(glm::vec3(currPos.x, 0.50001f, currPos.z));
		}
	}
}

