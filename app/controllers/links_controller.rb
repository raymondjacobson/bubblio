class LinksController < ApplicationController
	before_filter :bubble_owns_link
  
  def new
    respond_to do |format|
    	@link = @bubble.links.new(params[:link])
      bubble_id = @bubble.id.to_s
      @link.link_hash = generate_hash(bubble_id)
      @link.accessed_at = Time.new.inspect
      format.json { render :json => @link.link_hash.to_json }
      @link.save
    end
  end

  def create
    @link = @bubble.links.new(params[:link])
    bubble_id = @bubble.id.to_s
    @link.link_hash = generate_hash(bubble_id)
    @link.accessed_at = Time.new.inspect
    if @link.save
      flash[:success] = "Link generated!"
      redirect_to :back
    else
      render 'new'
    end
    return @link.link_hash
  end

  # def show
  # 	@link = @bubble.links.find(params[:id])
  # end

  def destroy
    @link = @bubble.links.find(params[:id])
    @link.destroy
    redirect_to :back
  end

 

end
