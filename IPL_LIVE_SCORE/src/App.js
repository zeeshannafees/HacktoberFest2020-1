import React, { Fragment, useEffect, useState } from "react";
// import logo from "./logo.svg";
import "./App.css";
import { Button, Grid } from "@material-ui/core";
import Navbar from "./components/Navbar";
import MyCard from "./components/MyCard";
import { getMatches } from "./components/api/API";

function App() {
  const [matches, setMatches] = useState([]);
  useEffect(() => {
    getMatches()
      .then((data) => {
        setMatches(data.matches);
        console.log(data.matches);
      })
      .catch((error) => alert("could not load data"));
  }, []);
  return (
    <div className="App">
      <Navbar />
      <h1>Welcome to My Live Cricket Score</h1>
      <Grid container>
        <Grid sm="2"></Grid>
        <Grid sm="8">
          {matches.map((match) => (
            <Fragment>
              {match.type == "Twenty20" ? (
                <MyCard key={match.unique_id} match={match} />
              ) : (
                ""
              )}
            </Fragment>
          ))}
        </Grid>
      </Grid>
      <div className="footer">
        Made with ❤️ Anjali Chauhan
      </div>
    </div>
  );
}

export default App;
