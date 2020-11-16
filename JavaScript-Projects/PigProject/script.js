'use strict';
// Selected both score elements by ID
const player0 = document.querySelector('.player--0');
const player1 = document.querySelector('.player--1');
const score0El = document.getElementById('score--0');
const score1El = document.getElementById('score--1');
const diceEl = document.querySelector('.dice'); // This is a way to select the id
//apparently get item ID is supposed to be faster than querySelector
const current0 = document.getElementById('current--0');
const current1 = document.getElementById('current--1');

//Rolling the dice functionality
const rollBtn = document.querySelector('.btn--roll');
const newBtn = document.querySelector('.btn--new');
const holdBtn = document.querySelector('.btn--hold');

let scores, curScore, activePlayer, playing; //Declared these outside init function to make sure it worked with the scope

const init = function () {
  curScore = 0;
  activePlayer = 0;
  score0El.textContent = 0;
  score1El.textContent = 0;
  scores = [0, 0];
  playing = true;
  score0El.textContent = 0;
  score1El.textContent = 0;
  current0.textContent = 0;
  current1.textContent = 0;
  player0.classList.remove('player--winner');
  player1.classList.remove('player--winner');
  player0.classList.remove('player--active');
  player1.classList.remove('player--active');
  player0.classList.add('player--active');
  diceEl.classList.add('hidden');
};
init();
const switchPlayer = function () {
  document.getElementById(`current--${activePlayer}`).textContent = 0;
  curScore = 0;
  activePlayer = activePlayer === 0 ? 1 : 0;
  player0.classList.toggle('player--active');
  player1.classList.toggle('player--active');
};
diceEl.classList.add('hidden');
rollBtn.addEventListener('click', function () {
  //Generate a random number and display that dice to the player
  //If that dice is a 1 wipe their current score and switch to the next player
  if (playing) {
    const rng = Math.trunc(Math.random() * 6 + 1);
    diceEl.classList.remove('hidden');
    console.log(rng);
    diceEl.src = `dice-${rng}.png`; //This is how you change the src of an image or whatever

    if (rng !== 1) {
      //Add to the current score
      curScore += rng;
      document.getElementById(
        `current--${activePlayer}`
      ).textContent = curScore;
    } else {
      switchPlayer();
    }
  }
});

holdBtn.addEventListener('click', function () {
  if (playing) {
    scores[activePlayer] += curScore;
    document.getElementById(`score--${activePlayer}`).textContent =
      scores[activePlayer];
    if (scores[activePlayer] >= 100) {
      playing = false;
      document
        .querySelector(`.player--${activePlayer}`)
        .classList.add('player--winner');
      document
        .querySelector(`.player--${activePlayer}`)
        .classList.toggle('player--active');
    } else {
      switchPlayer();
    }
  }
});

//Restting the Game button functionality
newBtn.addEventListener('click', init);
