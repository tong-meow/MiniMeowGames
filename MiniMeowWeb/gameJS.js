"use strict";

let canvas = document.getElementsByTagName("canvas")[0];

let ctx = canvas.getContext("2d");
let catImg = new Image();
catImg.src = "resources/nyancat.png";

let mouseX;
let mouseY;
let catX;
let catY;


canvas.onmousemove = function (event){
    mouseX = event.offsetX;
    mouseY = event.offsetY;

    catX = event.offsetX - (100/2);
    catY = event.offsetY - (70/2);
    if (event.offsetX < (100/2)){
        catX = 0;
    }else if (event.offsetX > canvas.width - 100/2){
        catX = canvas.width - 100;
    }
    if (event.offsetY < (70/2)){
        catY = 0;
    }else if (event.offsetY > canvas.height - 70/2){
        catY = canvas.height - 70;
    }
};


let ghostImg1 = new Image();
ghostImg1.src = "resources/ghost.png";
let ghostImg2 = new Image();
ghostImg2.src = "resources/ghost_reverse.png";
let timeCount = 0;
let ghosts = [];
let delta = 0.5;
let lives = 3;
let score = document.getElementById("score");

function ghostGen(){
    let x = Math.random() * (700 - 70);
    let y = Math.random() * (500 - 60);
    let ghost = {};
    ghost.posX = x;
    ghost.posY = y;
    if (ghost.posX < mouseX){
        ghost.img = ghostImg2;
    }else{
        ghost.img = ghostImg1;   
    }
    ghosts.push(ghost);
    ctx.drawImage(ghost.img, ghost.posX, ghost.posY, 70, 60);
}
 
function pageFresh(){
    timeCount++;
    if (timeCount % 100 == 0){
        ghostGen();
    }
    for (let ghost of ghosts){
        if (ghost.posX < mouseX){
            ghost.posX += delta;
            ghost.img = ghostImg2;
        }else{
            ghost.posX -= delta;
            ghost.img = ghostImg1;
        }

        if (ghost.posY < mouseY){
            ghost.posY += delta;
        }else{
            ghost.posY -= delta;
        }
    }

    ctx.clearRect(0, 0, canvas.width, canvas.height);
    for (let ghost of ghosts){
        ctx.drawImage(ghost.img, ghost.posX, ghost.posY, 70, 60);
    }
    ctx.drawImage(catImg, catX, catY, 100, 70);

    for (let i=0; i<ghosts.length; i++){
        let ghost = ghosts[i];
        if ( ghost.posX >= catX && ghost.posX <= catX + 70){
            if (ghost.posY >= catY && ghost.posY <= catY + 50){
                ghosts.splice(i, 1);
                lives--;
                score.innerText = lives;
                if (lives <= 0){
                    score.innerText = "0";
                    window.clearInterval(intervalId);
                    ctx.font = "bold 50px Arial";
                    ctx.fillStyle = "pink";
                    ctx.fillText("Game Over!", (canvas.width / 2) - 150, (canvas.height / 2) - 50);
                }
            }
        }
    }
}

function restartGame(){
    if (lives <= 0){
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        ghosts.splice(0, ghosts.length);
        intervalId = window.setInterval(pageFresh, 10);
        lives = 5;
        score.innerText = lives;
    }
}

let intervalId = window.setInterval(pageFresh, 10);
let restart = document.getElementById("restart");
restart.addEventListener("click", restartGame);