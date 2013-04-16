class ApplicationController < ActionController::Base
  protect_from_forgery

  def bubble_owns_item
  	@bubble = Bubble.find(params[:bubble_id] || params[:id])
  end

  def bubble_owns_link
  	@bubble = Bubble.find(params[:bubble_id] || params[:id])
  end

	def generate_hash(value) #NEEDS WORK STILL
		randvalue = ((('a'..'z').to_a + ('0'..'9').to_a).shuffle)[0..5].join
		#while ensure_random(randvalue)==false
		#	randvalue = ((('a'..'z').to_a + ('0'..'9').to_a).shuffle)[0..5].join
		#end
		#return randvalue;
	end

	def ensure_random(value)
		@bubbles = Bubble.all
		@bubbles.each do |bubble|
			bubble.links.each do |link|
				if link.link_hash == value
					return false
				end
			end
		end
		return true
	end

	def get_real_url(current_url)
		id = -1
		url_hash = current_url[-6,6]
		@bubbles.each do |bubble|
			bubble.links.each do |link|
				if link.link_hash == url_hash
					return bubble.id
				end
			end
		end
		return id
	end
end
