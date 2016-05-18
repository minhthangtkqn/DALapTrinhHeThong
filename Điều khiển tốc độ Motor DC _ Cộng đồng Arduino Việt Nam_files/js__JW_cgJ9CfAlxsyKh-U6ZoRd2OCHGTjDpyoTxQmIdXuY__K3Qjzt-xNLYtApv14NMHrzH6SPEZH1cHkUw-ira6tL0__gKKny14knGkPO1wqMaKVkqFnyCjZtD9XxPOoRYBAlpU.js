/* Source and licensing information for the line(s) below can be found at //cdn.arduino.vn/sites/all/modules/rate/rate.js. */
(function($){Drupal.behaviors.rate={attach:function(context){$('.rate-widget:not(.rate-processed)',context).addClass('rate-processed').each(function(){var widget=$(this),ids=widget.attr('id').split('--');ids=ids[0].match(/^rate\-([a-z]+)\-([0-9]+)\-([0-9]+)\-([0-9])$/);var data={content_type:ids[1],content_id:ids[2],widget_id:ids[3],widget_mode:ids[4]};$('a.rate-button',widget).click(function(){var token=this.getAttribute('href').match(/rate\=([a-zA-Z0-9\-_]{32,64})/)[1];return Drupal.rateVote(widget,data,token)})})}};Drupal.rateVote=function(widget,data,token){widget.trigger('eventBeforeRate',[data]);$(".rate-info",widget).text(Drupal.t('Saving vote...'));var random=Math.floor(Math.random()*99999),q=(Drupal.settings.rate.basePath.match(/\?/)?'&':'?')+'widget_id='+data.widget_id+'&content_type='+data.content_type+'&content_id='+data.content_id+'&widget_mode='+data.widget_mode+'&token='+token+'&destination='+encodeURIComponent(Drupal.settings.rate.destination)+'&r='+random;if(data.value)q=q+'&value='+data.value;widget=$('.'+widget.attr('id'));$.get(Drupal.settings.rate.basePath+q,function(response){if(response.match(/^https?\:\/\/[^\/]+\/(.*)$/)){document.location=response}else{var p=widget.parent();widget.trigger('eventAfterRate',[data]);widget.before(response);widget.remove();widget=undefined;Drupal.attachBehaviors(p)}});return false}})(jQuery);;
/* Source and licensing information for the above line(s) can be found at //cdn.arduino.vn/sites/all/modules/rate/rate.js. */
/* Source and licensing information for the line(s) below can be found at //cdn.arduino.vn/sites/all/modules/piwik/piwik.js. */
(function($){$(document).ready(function(){$(document.body).bind("mousedown keyup touchstart",function(event){$(event.target).closest("a,area").each(function(){if(Drupal.settings.piwik.trackMailto&&$(this).is("a[href^='mailto:'],area[href^='mailto:']"))_paq.push(["trackEvent","Mails","Click",this.href.substring(7)])})});$(document).bind("cbox_complete",function(){var href=$.colorbox.element().attr("href");if(href){_paq.push(["setCustomUrl",href]);_paq.push(["trackPageView"])}})})})(jQuery);;
/* Source and licensing information for the above line(s) can be found at //cdn.arduino.vn/sites/all/modules/piwik/piwik.js. */
