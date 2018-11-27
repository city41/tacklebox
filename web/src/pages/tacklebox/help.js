import React from "react";
import Layout from "../../components/tackleboxLayout";
import Hint from "../../components/hint";

import "./common.css";
import "./help.css";
import titleImg from "../../images/tackleboxTitle.png";
import dpadImg from "../../images/dpad.png";
import aButtonImg from "../../images/aButton.png";
import bButtonImg from "../../images/bButton.png";

const HelpPage = () => (
    <Layout className="help">
        <img className="titleImage" src={titleImg} alt="Ardynia Title Screen" />
        <p>
            Armed with ten bucks, a fishing pole and a dream, your quest is to
            find and catch the big one.
        </p>
        <h2>Controls</h2>
        <div className="controlsContainer">
            <div>
                <img src={dpadImg} alt="directional pad" />
            </div>
            <div>move around</div>
            <div>
                hold <img src={aButtonImg} alt="the a button" />
            </div>
            <div>Pick a place to fish</div>
            <div>
                press <img src={bButtonImg} alt="the b button" />
            </div>
            <div>Open the game menu</div>
            <div>
                <img src={dpadImg} alt="directional pad" />
            </div>
            <div>
                Left/right toggle between haul and length records in the
                collection menu
            </div>
        </div>
        <h2>Hints</h2>
        <Hint>Having trouble finding worms? try hunting for them at night</Hint>
        <Hint>Ocean fish aren't tempted by worms, you'll need better bait</Hint>
        <Hint>Got another old boot? Bummer. But, they do have a use!</Hint>
    </Layout>
);

export default HelpPage;
