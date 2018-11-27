import React from "react";
import Helmet from "react-helmet";
import Layout from "../../components/tackleboxLayout";
import Fish from "../../components/fish";

import "./common.css";
import "./index.css";
import fgLogoImg from "../../images/fgLogo.png";

const fishData = require("../../../../fish.json");

class FishGuide extends React.Component {
    constructor(props) {
        super(props);

        this.state = {
            agreedToNotTell: true,
            okWithSpoilers: true
        };
    }

    render() {
        const { agreedToNotTell, okWithSpoilers } = this.state;

        let pageBody = null;

        if (agreedToNotTell && okWithSpoilers) {
            pageBody = (
                <React.Fragment>
                    {fishData.fish
                        .filter(f => f.name !== "OLD BOOT")
                        .map(fish => (
                            <Fish className="fish" data={fish} />
                        ))}
                </React.Fragment>
            );
        } else {
            pageBody = (
                <div>
                    <h1>Please check these to see the guide</h1>
                    <div>
                        <input
                            onClick={() =>
                                this.setState({ agreedToNotTell: true })
                            }
                            type="checkbox"
                        />
                        I won't tell other players about this page
                    </div>
                    <div>
                        <input
                            onClick={() =>
                                this.setState({ okWithSpoilers: true })
                            }
                            type="checkbox"
                        />
                        I am OK with spoilers
                    </div>
                </div>
            );
        }

        return (
            <>
                <Helmet>
                    <meta
                        name="viewport"
                        content="width=device-width, initial-scale=1"
                    />
                </Helmet>
                <Layout className="fg">
                    <img
                        className="titleImage"
                        src={fgLogoImg}
                        alt="Fish Guide Logo"
                    />
                    <div className="guideContainer">{pageBody}</div>
                    <p>&copy;2018 Matt Greer</p>
                </Layout>
            </>
        );
    }
}

export default FishGuide;
