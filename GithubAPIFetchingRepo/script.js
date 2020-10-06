//Function to obtain last three commits for a repository
function getLastThreeCommits(username,repoName){

    //Establish a HTTP request Object
    const req = new XMLHttpRequest();

    //API endpoint for commits
    req.open("GET",`https://api.github.com/repos/${username}/${repoName}/commits`,"true");

    //When the Api send data-->
    req.onload = function(){
        //Obtaining last three commits
        const commitsArray = JSON.parse(this.response);
        let commits = commitsArray.slice(0,3);

        //Hiding the repositories.
        container.innerHTML = "";

        //Iterating over the array of last three commits.
        commits.forEach(commitObj =>{

            //Creating a container to show commits
            const commitContainer = document.createElement("div");
            commitContainer.setAttribute("class","commitContainer")

            //Repo name in heading of the commit container
            const h2 = document.createElement("h2");
            h2.innerHTML = repoName;

            //Showing the name of the committer
            const name = document.createElement("p");
            name.innerText = `Commiter: ${commitObj.commit.committer.name}`;

            //Date and time of commit
            const dateTime = document.createElement("p");
            const date = commitObj.commit.committer.date.slice(0,10);
            const time = commitObj.commit.committer.date.slice(11,-1);
            dateTime.innerText = `${date}, ${time}`;

            //Link to show commit changes made.
            const commitChanges = document.createElement("a");
            commitChanges.setAttribute("href",`${commitObj.html_url}`);
            commitChanges.setAttribute("target","_blank");
            commitChanges.innerHTML = "See commit changes";

            //Appending all the commit elements to the commit container.
            commitContainer.appendChild(h2);
            commitContainer.appendChild(name);
            commitContainer.appendChild(dateTime);
            commitContainer.appendChild(commitChanges);

            //Appending commit container to commit container outer
            commitContainerOuter.appendChild(commitContainer);
        });
    }

    //Sending request object
    req.send();
}


//Function to obtain all repositories of a user.
function getUsersRepos(){

    //hide commits if already appended.
    commitContainerOuter.innerHTML = "";

    container.style.display="block";
    //Obtaining username from input
    const username = inpId.value;

    //Creating a HTTP request object
    const request = new XMLHttpRequest();

    //Specifying the API endpoint and the method also.
    request.open("GET",`https://api.github.com/users/${username}/repos`,"true");

    //When the response is received.
    request.onload = function(){
        //Converting the JSON data to array of repositories
        const data = JSON.parse(this.response);

        //Traversing through the repositories
        data.forEach((element)=>{

            console.log(element);

            //Creating a card  div element for each repo
            const card = document.createElement("div");

            //Setting the c=attribute for each card
            card.setAttribute("class","card");

            //Showing the name of repo in form of link.
            const h2 = document.createElement("h2");
            const a = document.createElement("a");
            a.setAttribute("href",`${element.html_url}`);
            card.setAttribute("class","card");
            a.innerHTML = element.name;

            //Showing the languages used.
            const languages = document.createElement("h3");
            languages.setAttribute("class","language");
            if(element.language==null){
                languages.style.display = "none";
            }
            else{
                languages.textContent = `Language: ${element.language}`;
            }

            //Showing a brief introduction about each repository.
            const desc = document.createElement("div");
            desc.setAttribute("class","description");
            if(element.description==null){
                desc.textContent = "No description";
            }
            else{
                desc.textContent = element.description;
            }

            //Button for last three commits
            const commitButton = document.createElement("button")
            commitButton.setAttribute("class","commit-btn");
            commitButton.setAttribute("type","submit");
            commitButton.innerHTML = "Last three commits"
            commitButton.addEventListener("click",getLastThreeCommits.bind(null,username,element.name));

            //Appending the repo name to the card
            h2.appendChild(a);
            card.appendChild(h2);

            //Appending the languages to the card
            card.appendChild(languages);
            //Appending the description to the card.
            card.appendChild(desc)

            //Appending the commit button to the card.
            card.appendChild(commitButton);

            //Appending the repo card to the container element.
            container.appendChild(card);
        });
    }

    //Sending the http request to the server.
    request.send();


}

//Getting the input field.
const inpId = document.getElementById("inp");

//Getting the button field
const btn = document.getElementById("btn");

//Obtaining the  main container that will hold the input field,button and the container.
const mainContainer = document.getElementById("main-container");


//Creating a container inside the mainContainer
const container = document.createElement("div");
container.setAttribute("id","repositories");

//Creating a container for commits
const commitContainerOuter = document.createElement("div");
commitContainerOuter.setAttribute("id","commitContainerOuter");

mainContainer.appendChild(container);
mainContainer.appendChild(commitContainerOuter);
//On clicking button obtain the repos from the Github.
btn.onclick = getUsersRepos;




