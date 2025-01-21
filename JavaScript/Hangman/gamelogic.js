export let revealedWord;
export let attempts;
export let timeLeft;
export let timerInterval;



export function renderWord(wordContainer) {
  wordContainer.textContent = revealedWord.join(" ");
}


export function renderLives(livesContainer, attempts) {
  livesContainer.innerHTML = "";
  for (let i = 0; i < attempts; i++) {
    const heart = document.createElement("span");
    heart.textContent = "❤"; 
    heart.style.color = "red";
    heart.style.margin = "0 5px";
    livesContainer.appendChild(heart);
  }
}

export function handleLetterClick(letter, button, chosenWord, renderWordCallback, renderLivesCallback, checkWinCallback, endGameCallback) {
  button.classList.add("disabled");
  button.removeEventListener("click", handleLetterClick);

  if (chosenWord.name.includes(letter)) {
    chosenWord.name.split("").forEach((char, index) => {
      if (char === letter) {
        revealedWord[index] = letter;
      }
    });
    renderWordCallback();
    checkWinCallback();
    timeLeft = 60;
  } else {
    attempts--;
    renderLivesCallback();
    timeLeft = 60;
    if (attempts === 0) {
      endGameCallback(false);
    }
  }
}

export function disableAllButtons() {
  const buttons = document.querySelectorAll(".letter");
  buttons.forEach(button => button.classList.add("disabled"));
}

export function startTimer(timerContainer, endGameCallback) {
  timerInterval = setInterval(() => {
    timeLeft--;
    timerContainer.textContent = `Time Left: ${timeLeft} seconds`;
    if (timeLeft === 0) {
      endGameCallback(false);
    }
  }, 1000);
}
