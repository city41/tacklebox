(window.webpackJsonp=window.webpackJsonp||[]).push([[3],{140:function(e,t,n){"use strict";n.r(t);var a=n(0),r=n.n(a),i=n(155);t.default=function(){return r.a.createElement(i.a,null,r.a.createElement("h1",null,"not found :("),r.a.createElement("p",null,"You just hit a route that doesn't exist... the sadness."))}},147:function(e,t,n){"use strict";n.r(t),n.d(t,"graphql",function(){return y}),n.d(t,"StaticQueryContext",function(){return p}),n.d(t,"StaticQuery",function(){return f});var a=n(0),r=n.n(a),i=n(8),o=n.n(i),c=n(146),u=n.n(c);n.d(t,"Link",function(){return u.a}),n.d(t,"withPrefix",function(){return c.withPrefix}),n.d(t,"navigate",function(){return c.navigate}),n.d(t,"push",function(){return c.push}),n.d(t,"replace",function(){return c.replace}),n.d(t,"navigateTo",function(){return c.navigateTo});var s=n(34);n.d(t,"waitForRouteChange",function(){return s.c});var l=n(148),d=n.n(l);n.d(t,"PageRenderer",function(){return d.a});var m=n(35);n.d(t,"parsePath",function(){return m.a});var p=r.a.createContext({}),f=function(e){return r.a.createElement(p.Consumer,null,function(t){return e.data||t[e.query]&&t[e.query].data?(e.render||e.children)(e.data?e.data.data:t[e.query].data):r.a.createElement("div",null,"Loading (StaticQuery)")})};function y(){throw new Error("It appears like Gatsby is misconfigured. Gatsby related `graphql` calls are supposed to only be evaluated at compile time, and then compiled away,. Unfortunately, something went wrong and the query was left in the compiled code.\n\n.Unless your site has a complex or custom babel/Gatsby configuration this is likely a bug in Gatsby.")}f.propTypes={data:o.a.object,query:o.a.string.isRequired,render:o.a.func,children:o.a.func}},148:function(e,t,n){var a;e.exports=(a=n(150))&&a.default||a},149:function(e){e.exports={data:{site:{siteMetadata:{title:"Ardynia",keywords:"ArduBoy, game, zelda style, adventure",description:"An adventure game for the ArduBoy in the style of Zelda",twitterHandle:"@mattegreer"}}}}},150:function(e,t,n){"use strict";n.r(t);var a=n(0),r=n.n(a),i=n(8),o=n.n(i),c=n(36),u=n(1),s=function(e){var t=e.location,n=u.default.getResourcesForPathname(t.pathname);return r.a.createElement(c.a,{location:t,pageResources:n})};s.propTypes={location:o.a.shape({pathname:o.a.string.isRequired}).isRequired},t.default=s},151:function(e,t,n){},153:function(e,t,n){},155:function(e,t,n){"use strict";var a=n(149),r=n(0),i=n.n(r),o=n(156),c=n.n(o),u=n(8),s=n.n(u),l=n(157),d=n.n(l),m=n(147),p=(n(50),n(151),["updates","contact"]),f=function(e){return e.siteTitle,i.a.createElement("nav",{className:"header"},i.a.createElement("ul",null,i.a.createElement("li",null,i.a.createElement(m.Link,{to:"/"},"home")),p.map(function(e){return i.a.createElement("li",null,i.a.createElement(m.Link,{to:"/"+e},e))})))},y=(n(153),function(e){var t=e.className,n=e.children,r=c()("layout",t);return i.a.createElement(m.StaticQuery,{query:"2840028964",render:function(e){return i.a.createElement(i.a.Fragment,null,i.a.createElement(d.a,{title:e.site.siteMetadata.title,meta:[{name:"description",content:e.site.siteMetadata.title},{name:"keywords",content:e.site.siteMetadata.keywords},{name:"twitter:card",content:"summary"},{name:"twitter:site",content:e.site.siteMetadata.twitterHandle},{name:"twitter:title",content:e.site.siteMetadata.title},{name:"twitter:description",content:e.site.siteMetadata.description},{name:"twitter:image",content:"http://www.ardynia.com/title.png"},{name:"og:title",content:e.site.siteMetadata.title},{name:"og:type",content:"website"},{name:"og:url",content:"http://www.ardynia.com"},{name:"og:description",content:e.site.siteMetadata.description},{name:"og:image",content:"http://www.ardynia.com/title.png"},{name:"og:title",content:e.site.siteMetadata.title}]},i.a.createElement("html",{lang:"en"})),i.a.createElement(f,{siteTitle:e.site.siteMetadata.title}),i.a.createElement("div",{className:"layoutContainer"},i.a.createElement("div",{className:r},n)))},data:a})});y.propTypes={children:s.a.node.isRequired},t.a=y}}]);
//# sourceMappingURL=component---src-pages-404-js-8c3c3aee5e0257fc0df0.js.map