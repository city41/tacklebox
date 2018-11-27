import React from "react";
import { Link } from "gatsby";

import "./header.css";

const Header = ({ pages }) => (
    <nav className="header">
        <ul>
            {pages.map(p => (
                <li>
                    <Link to={p.url}>{p.label}</Link>
                </li>
            ))}
        </ul>
    </nav>
);

export default Header;
