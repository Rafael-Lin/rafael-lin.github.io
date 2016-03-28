$(document).ready(function() {
  $('#fullpage').fullpage({
    sectionsColor: ['#1bbc9b', '#4BBFC3', '#7BAABE', 'whitesmoke', '#ccddff'],
    anchors: ['home', 'about', 'portfolio', 'contact'],
    menu: '#menu',
    scrollingSpeed: 1000,
    fitToSection: true ,
    responsiveHeight: 600
  });

});
