#include "SolarSystem.h"

SolarSystem::SolarSystem() {
	bunkers = 2;
	fuels = 1;
}

void SolarSystem::setupPlanets(){
	alfa.setnBunkers(bunkers);
	beta.setnBunkers(bunkers+1);
	gamma.setnBunkers(bunkers+2);
	omega.setnBunkers(bunkers+3);
	bunkers++;
	alfa.setnFuels(fuels);
	beta.setnFuels(fuels+1);
	gamma.setnFuels(fuels+2);
	omega.setnFuels(fuels+3);
}
