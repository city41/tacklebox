(window.webpackJsonp=window.webpackJsonp||[]).push([[3],{140:function(t,e,n){"use strict";n.r(e);var a=n(0),r=n.n(a),i=n(155);e.default=function(){return r.a.createElement(i.a,null,r.a.createElement("h1",null,"not found :("),r.a.createElement("p",null,"You just hit a route that doesn't exist... the sadness."))}},147:function(t,e,n){"use strict";n.r(e),n.d(e,"graphql",function(){return h}),n.d(e,"StaticQueryContext",function(){return p}),n.d(e,"StaticQuery",function(){return f});var a=n(0),r=n.n(a),i=n(8),o=n.n(i),c=n(146),u=n.n(c);n.d(e,"Link",function(){return u.a}),n.d(e,"withPrefix",function(){return c.withPrefix}),n.d(e,"navigate",function(){return c.navigate}),n.d(e,"push",function(){return c.push}),n.d(e,"replace",function(){return c.replace}),n.d(e,"navigateTo",function(){return c.navigateTo});var s=n(34);n.d(e,"waitForRouteChange",function(){return s.c});var l=n(148),d=n.n(l);n.d(e,"PageRenderer",function(){return d.a});var m=n(35);n.d(e,"parsePath",function(){return m.a});var p=r.a.createContext({}),f=function(t){return r.a.createElement(p.Consumer,null,function(e){return t.data||e[t.query]&&e[t.query].data?(t.render||t.children)(t.data?t.data.data:e[t.query].data):r.a.createElement("div",null,"Loading (StaticQuery)")})};function h(){throw new Error("It appears like Gatsby is misconfigured. Gatsby related `graphql` calls are supposed to only be evaluated at compile time, and then compiled away,. Unfortunately, something went wrong and the query was left in the compiled code.\n\n.Unless your site has a complex or custom babel/Gatsby configuration this is likely a bug in Gatsby.")}f.propTypes={data:o.a.object,query:o.a.string.isRequired,render:o.a.func,children:o.a.func}},148:function(t,e,n){var a;t.exports=(a=n(150))&&a.default||a},149:function(t){t.exports={data:{site:{siteMetadata:{title:"Ardynia"}}}}},150:function(t,e,n){"use strict";n.r(e);var a=n(0),r=n.n(a),i=n(8),o=n.n(i),c=n(36),u=n(1),s=function(t){var e=t.location,n=u.default.getResourcesForPathname(e.pathname);return r.a.createElement(c.a,{location:e,pageResources:n})};s.propTypes={location:o.a.shape({pathname:o.a.string.isRequired}).isRequired},e.default=s},151:function(t,e,n){},153:function(t,e,n){},155:function(t,e,n){"use strict";var a=n(149),r=n(0),i=n.n(r),o=n(156),c=n.n(o),u=n(8),s=n.n(u),l=n(157),d=n.n(l),m=n(147),p=(n(50),n(151),["updates","contact"]),f=function(t){return t.siteTitle,i.a.createElement("nav",{className:"header"},i.a.createElement("ul",null,i.a.createElement("li",null,i.a.createElement(m.Link,{to:"/"},"home")),p.map(function(t){return i.a.createElement("li",null,i.a.createElement(m.Link,{to:"/"+t},t))})))},h=(n(153),function(t){var e=t.className,n=t.children,r=c()("layout",e);return i.a.createElement(m.StaticQuery,{query:"2262439644",render:function(t){return i.a.createElement(i.a.Fragment,null,i.a.createElement(d.a,{title:t.site.siteMetadata.title,meta:[{name:"description",content:t.site.siteMetadata.title},{name:"keywords",content:t.site.siteMetadata.keywords},{name:"twitter:card",content:"summary"},{name:"twitter:site",content:t.site.siteMetadata.twitterHandle},{name:"twitter:title",content:t.site.siteMetadata.title},{name:"twitter:description",content:t.site.siteMetadata.description},{name:"twitter:image",content:"http://www.ardynia.com/title.png"},{name:"og:title",content:t.site.siteMetadata.title},{name:"og:type",content:"website"},{name:"og:url",content:"http://ardynia.com"},{name:"og:description",content:t.site.siteMetadata.description},{name:"og:image",content:"http://www.ardynia.com/title.png"},{name:"og:title",content:t.site.siteMetadata.title}]},i.a.createElement("html",{lang:"en"})),i.a.createElement(f,{siteTitle:t.site.siteMetadata.title}),i.a.createElement("div",{className:"layoutContainer"},i.a.createElement("div",{className:r},n)))},data:a})});h.propTypes={children:s.a.node.isRequired},e.a=h}}]);
//# sourceMappingURL=component---src-pages-404-js-1aa34578c1345894e5a4.js.map