#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Scene.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	App->map->DrawChainsBoard();

	debug_mode = false;
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	//LOAD AND SAVE FUNCTIONS
		if(App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
			App->LoadGame("save_game.xml");

		if(App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
			App->SaveGame("save_game.xml");

	//CAMERA DEBUGS
		if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
		{
			if (debug_mode)
				debug_mode = false;
			debug_mode = true;
		}
		if (debug_mode)
		{
			if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
				App->render->camera.y += 1;

			if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
				App->render->camera.y -= 1;

			if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
				App->render->camera.x += 1;

			if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
				App->render->camera.x -= 1;
		}

		// Left flippers
		/*if ((App->input->GetKey(SDL_SCANCODE_Z) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_Z) == KEY_REPEAT))
			App->map->l_flipper_joint->SetMotorSpeed(400);
		else if ((App->input->GetKey(SDL_SCANCODE_Z) == KEY_UP))
			App->map->l_flipper_joint->SetMotorSpeed(-200);*/

		// Right flippers
		/*if ((App->input->GetKey(SDL_SCANCODE_M) == KEY_DOWN))
			App->map->r_flipper_joint->SetMotorSpeed(-400);
		if ((App->input->GetKey(SDL_SCANCODE_M) == KEY_UP))
			App->map->r_flipper_joint->SetMotorSpeed(200);
*/
		// Spring
		if ((App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN))
			//LATER

		// Create a new ball
		if ((App->input->GetKey(SDL_SCANCODE_N) == KEY_DOWN))
		{
			//NewBall();
		}

		// Draw ----------

		App->map->Draw();

		// ---------------

		

	int x, y;
	App->input->GetMousePosition(x, y);
	iPoint map_coordinates = { x - App->render->camera.x, y - App->render->camera.y };
	p2SString title("Mouse: %d, x -- %d y",map_coordinates.x, map_coordinates.y);

	App->win->SetTitle(title.GetString());
	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}

void j1Scene::NewBall()
{
	//App->map->ball->pb = App->physics->CreateCircle(600, 980, 10, 0x0002, 0x0001);
}