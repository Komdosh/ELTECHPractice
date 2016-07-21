#include "Game.h"
#include "mainWindow.h"

using namespace SlaSolGame;

SlaSolGame::Game::Game(int iFieldSize, int iColors) :fieldSize(iFieldSize), colors(iColors), steps(0), scores(0) {}

int Game::getSteps() {
	return steps;
}

void Game::setSteps(int count) {
	steps = count;
}

void Game::incSteps() {
	++steps;
}

int Game::getClicks() {
	return clicks;
}
void  Game::setClicks(int count) {
	clicks = count;
}

void  Game::decClicks() {
	--clicks;
}

int Game::getScores() {
	return scores;
}

void Game::setScores(int value) {
	scores = value;
}

void Game::addScores(int value) {
	scores += value;
}

int Game::getFieldSize(){
	return fieldSize;
}

void Game::setFieldSize(int value){
	fieldSize = value;
}

int Game::getColors(){
	return colors;
}

void Game::setColors(int value){
	colors = value;
}

void Game::clearCounters() {
	steps = 0;
	clicks = 0;
}

int Game::checkerFinishRound(bool check) {
	if (check) {
		win();
		return 1;
	}
	if (clicks == 0) {
		loose();
		return -1;
	}
	return 0;
}